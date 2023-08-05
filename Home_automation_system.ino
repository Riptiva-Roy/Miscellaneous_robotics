

#include<SoftwareSerial.h>
SoftwareSerial bluetooth(0,1);
boolean conversion; // this variable can be true or false

void setup() {
  
// put your setup code here, to run once:
bluetooth.begin(9600);
Serial.begin(9600);
pinMode(5, OUTPUT); // relay board 
pinMode(7,OUTPUT); // buzzer 
pinMode (A5, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
//check whether arduino is receiving signal or not
   //reads the signal
//Serial.print(val);
/*********For Forward motion*********/
}

val = analogRead(A5); 
Serial.println(val); 
if (conversion==true)
{
if (val < 700)

{
Serial.println("ON");
digitalWrite(5, HIGH);
digitalWrite(7,HIGH); 
}


if (val > 700)

{
Serial.println("OFF");
digitalWrite(5, LOW);
digitalWrite(7,LOW);
}

delay(1000); 

}

if (conversion==false)
{
  if (data == 'A')
{
Serial.println("ON");
digitalWrite(5, HIGH);
digitalWrite(7,HIGH); 

}
if (data == 'B')
{
Serial.println("OFF");
digitalWrite(5, LOW);
digitalWrite(7,LOW);

}


}


if (data == 'A')
{
Serial.println("ON");
digitalWrite(5, HIGH);
digitalWrite(7,HIGH); 

}
if (data == 'B')
{
Serial.println("OFF");
digitalWrite(5, LOW);
digitalWrite(7,LOW);

}

if (data == 'O')
{
  conversion = true;

}

if (data == 'F')
{
  conversion = false;

}


}

}
