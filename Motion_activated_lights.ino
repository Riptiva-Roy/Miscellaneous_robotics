// Project = motion-activated LED light system using two PIR sensors. 
//The PIR sensors are used to detect motion and turn on the LED light when motion is detected.
//The Arduino board is used to receive data from the PIR sensors, control the LED light, and communicate with a computer or mobile device via the serial monitor.

//Steps:
//0 - Add the necessary libraries
//1 - define the pin numbers for the LED and PIR sensors. 
//2 - set up the LED pin as an output and the PIR sensor pins as inputs. 
//3 - initialise serial communication
//4 - main loop of the code continuously reads the status of the two PIR sensors. 
//5 - If either of the sensors detect motion, the LED is turned on 
//6 - message is printed to the serial monitor indicating that motion was detected. 
//7 - If no motion is detected, the LED is turned off.

//use delay function to slow down process of reading the 2 PIR sensors.


#include <Keypad.h>
#include <SoftwareSerial.h>

const byte ROWS = 4;
const byte COLS = 4
char keys[ROWS][COLS] = 
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};


byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int PIR_1 = A0;
const int PIR_2 = A1;
const int LED_1 = 10;
const int LED_2 = 11;
int pir_1_state = LOW;
int pir_2_state = LOW;
int pir_1_val = 0;
int pir_2_val = 0;

const int joyX = A2;
const int joyY = A3;
const int joyButton = 12;
int joyX_val = 0;
int joyY_val = 0;
int joyButton_val = 0;
int prevJoyButton_val = HIGH;

SoftwareSerial bluetooth(13, 14); // RX, TX

void setup() {
  pinMode(PIR_1, INPUT);
  pinMode(PIR_2, INPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    if (key == 'A') {
      digitalWrite(LED_1, LOW);
      digitalWrite(LED_2, LOW);
    } else if (key == 'B') {
      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_2, HIGH);
    }
  }

  pir_1_val = digitalRead(PIR_1);
  pir_2_val = digitalRead(PIR_2);
  if (pir_1_val == HIGH || pir_2_val == HIGH) {
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
  }

  joyX_val = analogRead(joyX);
  joyY_val = analogRead(joyY);
  joyButton_val = digitalRead(joyButton);
  if (joyButton_val == LOW && prevJoyButton_val == HIGH) {
    bluetooth.println("Joystick Button Pressed");
  }
  prevJoyButton_val = joyButton_val;

  String data = "PIR 1: " + String(pir_1_val) + ", PIR 2: " + String(pir_2_val) + ", Joystick X: " + String(joyX_val) + ", Joystick Y: " + String(joyY_val);
  Serial.println(data);
  bluetooth.println(data);
  delay(500);
}
