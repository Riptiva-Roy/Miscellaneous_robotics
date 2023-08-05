void setup() {
    pinMode(2, OUTPUT);
     pinMode(3, OUTPUT);
     pinMode(5, OUTPUT);
     pinMode(5, OUTPUT);
    
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
int D1 = digitalRead(4);
int D2 = digitalRead(8);
int D3 = digitalRead(9);
int D4 = digitalRead(2);


if ((D4==0 ) && ( D3==0)  && (D2==0) && (D1==1))

{
F();

}

}
void F(){
digitalWrite (2, HIGH);
digitalWrite (3, LOW);
digitalWrite (4, HIGH);
digitalWrite (5, LOW);
  
}

if ((D4==0 ) && ( D3==0)  && (D2==1) && (D1==1))

{
F();

}

}
void F(){
digitalWrite (2, HIGH);
digitalWrite (3, LOW);
digitalWrite (4, LOW);
digitalWrite (5, LOW);
  
}

if ((D4==0 ) && ( D3==0)  && (D2==1) && (D1==0))

{
F();

}

}
void F(){
digitalWrite (2, LOW);
digitalWrite (3, LOW);
digitalWrite (4, HIGH);
digitalWrite (5, LOW);
  
}

if ((D4==0 ) && ( D3==1)  && (D2==0) && (D1==0))

{
F();

}

}
void F(){
digitalWrite (2, LOW);
digitalWrite (3, HIGH);
digitalWrite (4, LOW);
digitalWrite (5, HIGH);
  
}
if ((D4==0 ) && ( D3==0)  && (D2==1) && (D1==0))

{
F();

}

}
void F(){
digitalWrite (2, LOW);
digitalWrite (3, LOW);
digitalWrite (4, LOW);
digitalWrite (5, LOW);
  
}
