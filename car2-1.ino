 #include <AFMotor.h>//library for motor driver
#include <HCSR04.h>//library for ultrasonic sensor
//creating functions for drive mode
void forward();
void reverse();
void halt();
void left();
void right();
// declaring proximity variiables
float duration, d;
// declarations of pins
int echopin = 13;
int trigpin = 12;
int rightfw = 5;
int lftfrwd = 3;
int lftback = 2;
int rightbck = 4;
char val;


void setup() {
  //pinMode(11,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(lftfrwd,OUTPUT);
  pinMode(lftback,OUTPUT);
  pinMode(rightfw,OUTPUT);
  pinMode(rightbck,OUTPUT);
  Serial.begin(9600);
  //digitalWrite(11,HIGH);

}

void loop()
{
       
  
       if (Serial.available() > 0){
        val = Serial.read();
        if(val =='F' )
       {
        //forward();
        digitalWrite(trigpin,LOW);
         delay(2);
        digitalWrite(trigpin,HIGH);
          delay(10);
        digitalWrite(trigpin,LOW);
         duration = pulseIn(echopin,HIGH);
           d = (duration*.0343)/2;
        Serial.println("d");
        Serial.println(d);
        delay(100);
       
         if(d<10)
      {
        halt();
      }
      else{
        forward();
       }
           }
       else if(val =='B')
       {
        reverse();
       }
        else if(val =='R')
       {
        right();
       }
       else if(val =='L')
       {
        left();
       }
       else if(val =='S')
       {
        halt();
       }
      }
}

void forward()
{
   digitalWrite(lftfrwd, HIGH);
   digitalWrite(rightfw, HIGH);
  }
void reverse()
{
  digitalWrite(rightbck, HIGH);
  digitalWrite(lftback, HIGH);
}
void halt()
{
   digitalWrite(lftfrwd, LOW);
   digitalWrite(rightfw, LOW);
  digitalWrite(rightbck, LOW);
  digitalWrite(lftback, LOW);
}
void left()
{
   digitalWrite(rightfw, HIGH);
  digitalWrite(lftback, HIGH);
}
void right()
{
   digitalWrite(rightbck, HIGH);
   digitalWrite(lftfrwd, HIGH);
}
