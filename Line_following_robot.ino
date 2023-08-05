/*

*/
//2 sensors and 2 motors


int lir = A0;
int rir = A1;

int lmp = 6;
int lmn = 7;

int rmp = 8;
int rmn = 9;

void forward()

{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn, LOW);
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn, LOW);
}

void setup() {
  
  pinMode(lir,INPUT);
  pinMode(rir,INPUT);
  
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
    
  Serial.begin(9600);
}

//anything in set up is executed only once nd it declares all devices that are connected to arduino

void loop() {
  
int left = analogRead(lir);
int right = analogRead(rir);
Serial.print(left);
Serial.print("/t"); //t means give a tab spacing
Serial.println(right);

//both sensors point down and get value of *750* = white
//both sensors point down and get value of *400* = black

if(left>600 && right>600)
{
  forward();
}

 if(left<600 && right<600)
{
  halt();
}   
 if(left<600 && right>600)
{
  left();
} 

 if(left>600 && right<600)
{
  right();
} 

}
