#include <Servo.h>

Servo servo0;
Servo servo1;
Servo servo2;
Servo servo3;
void setup()

{

  servo0.attach(5);
  servo1.attach(6);
  servo2.attach(9);
  servo3.attach(10);

  Serial.begin(9600);

}
int last0 = -1,last1 = -1,last2 = -1,last3 = -1;
void loop()

{

  int angle0 = analogRead(A0);
  int angle1 = analogRead(A1);
  int angle2 = analogRead(A2);
  int angle3 = analogRead(A3);

  angle0 = map(angle0, 0, 650, 180, 0);
  if(angle0 - last0 < 5 && angle0 - last0 > -5) angle0 = last0;
  angle1 = map(angle1, 0, 650, 180, 0);
  if(angle1 - last1 < 5 && angle1 - last1 > -5) angle1 = last1;
  angle2 = map(angle2, 0, 650, 180, 0);
  if(angle2 - last2 < 5 && angle2 - last2 > -5) angle2 = last2;
  angle3 = map(angle3, 0, 650, 180, 0);
  if(angle3 - last3 < 5 && angle3 - last3 > -5) angle3 = last3;
  
  Serial.print("angle = ");
  Serial.print(angle3);
  Serial.print("   last = ");
  Serial.println(last3);

  servo0.write(angle0);
  last0 = angle0;
  servo1.write(angle1);
  last1 = angle1;
  servo2.write(angle2);
  last2 = angle2;
  servo3.write(angle3);
  last3 = angle3;
  delay(15);

}
