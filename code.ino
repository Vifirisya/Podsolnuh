#include <Servo.h>

Servo sx;
Servo sy;
int a1 = 0;
int a2 = 0;

void setup() {
  sx.attach(6);
  sy.attach(9);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A7, INPUT);
  Serial.begin(9600);

  sx.write(0);
  sy.write(0);
}

void loop() {
  int d1 = analogRead(A0); //NL
  int d2 = analogRead(A1); //NP
  int d5 = analogRead(A7); //nz
  int d4 = analogRead(A5); //VV
  int d3 = analogRead(A4); //vn
  if (d2>8 and d1<65){
    a1+=5;
    if (a1>180){
      a1=180;
    }
    if (a1<0){
      a1=0;
    }
    sx.write(a1);
  }
  if (d2<8 and d1>65){
    a1-=5;
    if (a1>180){
      a1=180;
    }
    if (a1<0){
      a1=0;
    }
    sx.write(a1);
  }
  if (d5>15){
    if (a2>=90){
      a2=45;
    }
    if (d4<70 and d3>110){
      a2+=5;
    }
    if (d4>70 and d3<110){
      a2-=5;
    }
    sy.write(a2);
  }
  if (d5<15){
    if (a2<90){
      a2=135;
    }
    if (d4>90 and d3<110){
      a2-=5;
    }
    if (d4<90 and d3>110){
      a2+=5;
    }
    sy.write(a2);
  }
  if (a1==0 and d1>150){
    a1=90;
    a2=135;
    if (d4>90 and d3<110){
      a2-=5;
    }
    if (d4<90 and d3>110){
      a2+=5;
    }
  sy.write(a2);
  sx.write(a1);
  }
  if (a1==180 and d2>30){
    a1=90;
    a2=135;
    if (d4>90 and d3<110){
      a2-=5;
    }
    if (d4<90 and d3>110){
      a2+=5;
    }
    sy.write(a2);
    sx.write(a1);
  }
  delay(100);
  d1 = analogRead(A0);
  d2 = analogRead(A1);
  d3 = analogRead(A4);
  d4 = analogRead(A5);
  d5 = analogRead(A7);
  Serial.print(d1);
  Serial.print(" ");
  Serial.print(d2);
  Serial.print(" ");
  Serial.print(d3);
  Serial.print(" ");
  Serial.print(d4);
  Serial.print(" ");
  Serial.println(d5);
}
