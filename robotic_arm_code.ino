#include <SoftwareSerial.h> // TX RX software library for bluetooth
 
#include <Servo.h> // servo library 
Servo servo1, servo2, servo3, servo4; // servo name
SoftwareSerial bluetooth(3,4);
 
void setup()
{
  servo1.attach(5); 
  servo2.attach(6);
  servo3.attach(7);
  servo4.attach(8);

  servo1.write(90);
  servo2.write(30);
  servo3.write(50);
  servo4.write(180);
  
  //Setup Bluetooth serial connection to android
  bluetooth.begin(9600);
}
 
void loop()
{
  
  if(bluetooth.available()>= 2 )
  {
    unsigned int servobit1 = bluetooth.read();
    unsigned int servobit2 = bluetooth.read();
    unsigned int realservo = (servobit2 *256) + servobit1;
    int servo1pos;
    int servo2pos;
    int servo3pos;
    int servo4pos;
 
    if (realservo >= 1000 && realservo <1180) {
       servo1pos = realservo;
      servo1pos = map(servo1pos, 1000, 1180, 0, 180);
      servo1.write(servo1pos);
          delay(10);
    }
    if (realservo >= 2000 && realservo <2180) {
       servo2pos = realservo;
      servo2pos = map(servo2pos, 2000, 2180, 0, 180);
      servo2.write(servo2pos);
      delay(10);
    }
    if (realservo >= 3000 && realservo <3180) {
       servo3pos = realservo;
      servo3pos = map(servo3pos, 3000, 3180, 0, 180);
      servo3.write(servo3pos);
      delay(10);
    }
    if (realservo >= 4000 && realservo <4180) {
       servo4pos = realservo;
      servo4pos = map(servo4pos, 4000, 4180, 0, 180);
      servo4.write(servo4pos);
      delay(10);
    }
  }
}