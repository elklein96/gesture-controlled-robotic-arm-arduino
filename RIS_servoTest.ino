#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
int serialData = 0;

void setup(){
  servo1.attach(13);
  servo2.attach(12);
  servo3.attach(11);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available() > 0){
    serialData = Serial.read();
    Serial.println(serialData);
  }
    //up
    if (serialData == 1){
      servo1.attach(13);
      servo1.writeMicroseconds(1000);
    }
    //down
    else if (serialData == 2){
      servo1.attach(13);
      servo1.writeMicroseconds(2000);
    }
    //right
    else if (serialData == 3){
      servo2.attach(12);
      servo2.writeMicroseconds(2000);
    }
    //left
    else if (serialData == 4){
      servo2.attach(12);
      servo2.writeMicroseconds(1000);
    }
    //claw up
    else if (serialData == 5){
      servo3.attach(11);
      servo3.writeMicroseconds(1000);
      delay(1000);
    }
    //claw down
    else if (serialData == 6){
      servo3.attach(11);
      servo3.writeMicroseconds(2000);
      delay(1000);
    }
   else{
     servo1.writeMicroseconds(1500);
     servo2.writeMicroseconds(1500);
     servo3.writeMicroseconds(1500);
     delay(20);
   }
}
