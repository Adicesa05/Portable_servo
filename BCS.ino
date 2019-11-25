//Button Controll Servo
// By Gwyn
//This code makes a servo rotate when you push a button.
//There are two button, one spins it one way and the other spins it the other

#include <Servo.h>

Servo myServo;

int btnPin1 = 3;
int btnPin2 = 4;
int servoPin = 8;
int btn1State;
int btn2State;
int angle = 0;
int ledPin = 10;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(8); //Servo pin is 8
  Serial.println("Hello world");
  myServo.write(90);



}

void loop() {
  // put your main code here, to run repeatedly:
  btn1State = digitalRead(btnPin1);
  btn2State = digitalRead(btnPin2);

  if (btn1State == HIGH && angle < 180) { //If button one is pressed and the servo angle is less than 180 then the servo will rotate and an LED will flash.
    myServo.write(angle++);
    Serial.print("Button 1 is on \t");
    Serial.println(angle);


  
  }
  else if (btn1State == LOW) { //If button one isn't being pressed, the Servo will not spin, and the LED will not go off.
    
  }


  if (btn2State == HIGH && angle > 0) { //If button two is pressed and the angle is more than 0, the Servo will spin and an LED will flash.
    myServo.write(angle -- );
    Serial.print("Button 2 is on");
Serial.println(angle); 
   

  }
  else if (btn2State == LOW) { //If button two isnt being pressed, the Servo will noy spin, and the LED will not go off.
  
  }
}
