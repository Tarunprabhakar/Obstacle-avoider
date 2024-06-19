#include <Servo.h>//totally written by me not frm any web -_-
/* The car consist of arduino uno R3 board,a servo motor for rotating the ultra sonic sensor,a ultra sonic sensor for detecting obstacles,two gear motors,three wheels,L298N
motor drivers,battery pack for power supply.
*/
Servo myservo;
//for motors 2 is right 1 is left
int m1c=4;//forward motion
int m2c=7;//forward motion
int m1a=5;//backward motion
int m2a=6;//backward motion
int dist,time;
int trig=10;//trigger pin or input pin for ursensor
int echo=11;//echo pin or output pin for ursensor which recives data
int l;
int r;
int y;
int distance(){//this is the function for calculating distance between the robot and the wall using speed of sound in air with ursensor
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    time=pulseIn(echo,HIGH);
    dist=(time*0.0343)/2;//0.0343 is speed of sound in air
    delay(100); 
    return dist;

}

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);//recevie data from ur sensor
  myservo.attach(12);//attach servo motor input side to dpin 12
  pinMode(m2c,OUTPUT);
  pinMode(m1c,OUTPUT);
  pinMode(m2a,OUTPUT);
  pinMode(m1a,OUTPUT);
}

void loop() {
  int y=distance();//calculates distance and stores it in variable y using function distance
  Serial.println(y);
  if(y>15){//if distance is less than 15 cm
    digitalWrite(m1c,HIGH);
    digitalWrite(m2c,HIGH);
  }
  else{
    Serial.println("obstacle");
    Serial.println(y);
    digitalWrite(m1c,LOW);
    digitalWrite(m2c,LOW);
    myservo.write(45);
    r=distance();
    Serial.println("right");
    Serial.println(r);
    delay(2000);
    myservo.write(180);
    l=distance();
    Serial.println("left");
    Serial.println(l);
    delay(2000);
    myservo.write(120);
    digitalWrite(m2a,HIGH);
    digitalWrite(m1a,HIGH);
    delay(1000);
    digitalWrite(m2a,LOW);
    digitalWrite(m1a,LOW);
    if(l>r){//there is more space in left
      digitalWrite(m2c,HIGH);
      delay(1000);
      digitalWrite(m2c,LOW);
      }
    else if(r>l){//there is more space in right
      digitalWrite(m1c,HIGH);
      delay(1000);
      digitalWrite(m1c,LOW);


    }  



}
  
 
  
}
