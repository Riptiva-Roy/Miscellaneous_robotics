#include <Key.h>
#include <Keypad.h>

const byte rows = 4;
const byte columns = 4; 
char keys[rows][columns] = {{'1', '2', '3', 'A'},{'4', '5', '6', 'B'},{'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}}; 
byte rowpins [rows] = {9,8,7,6};
byte columnpins [columns] = {5,4,3,2}; 
Keypad  keypad = Keypad (makeKeymap(keys),rowpins,columnpins,rows,columns);
char password1 [] = {'9','8','1','2'}; 
char password2 [] = {'9','8','2','3'}; 
char password3 [] = {'9','8','3','4'}; 
char password4 [] = {'9','8','4','5'}; 
char password5 [] = {'9','8','5','6'}; 
char password6 [] = {'9','8','6','7'}; 
int position = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:


char key = keypad.getKey();

if(key)
{
  Serial.println(key);
}

if (key== password1[position])

{
  position++;
  
}
if (position== 4)

{ 
  door1 ();
}

if (key== password2[position])

{
  position++;
  
}
if (position== 4)

{ 
  door2 ();
}

if (key== password3[position])

{
  position++;
  
}
if (position== 4)

{ 
  door3 ();
}

if (key== password4[position])

{
  position++;
  
}
if (position== 4)

{ 
  door4 ();
}

if (key== password5[position])

{
  position++;
  
}
if (position== 4)

{ 
  door5 ();
}

if (key== password6[position])

{
  position++;
  
}
if (position== 4)

{ 
  door6 ();
}
if (key=='*'|| key== '#')
{
Serial.println(key);
digitalWrite (13, LOW);
Serial.println("LED is off"); 
}


}

void door1 ()
{
digitalWrite (13, HIGH);
Serial.println("LED1 is on");

}

void door2 ()
{
digitalWrite (12, HIGH);
Serial.println("LED2 is on");

}

void door3 ()
{
digitalWrite (11, HIGH);
Serial.println("LED3 is on");

}

void door4 ()
{
digitalWrite (10, HIGH);
Serial.println("LED4 is on");

}

void door5 ()
{
digitalWrite (9, HIGH);
Serial.println("LED5 is on");

}

void door6 ()
{
digitalWrite (0, HIGH);
Serial.println("LED6 is on");

}


// try menu driven project 
// if you press 1, it does something, if you press 2, something else should happen
