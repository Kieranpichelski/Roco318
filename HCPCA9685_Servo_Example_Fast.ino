#include "HCPCA9685.h"  // Include the HCPCA9685 library
#define  I2CAdd 0x40    // I2C slave address for the device/module. For the HCMODU0097 the default I2C address is 0x40

HCPCA9685 HCPCA9685(I2CAdd); // Creates an instance of the library

void setup() 
{
  /* Initialise the library and set it to 'servo mode' */ 
  HCPCA9685.Init(SERVO_MODE);

  /* Wake the device up */
  HCPCA9685.Sleep(false);
}

  /* Servo Labels
   *  
  1   0   2              5   4   3
                BODY  
  6   7   8              11   9  10
  
  
  */

// HCPCA9685.Servo(servo_number, libconversion);

int angle(int angle){
  int libconversion;
  
  libconversion = map(angle, 0, 180, 10, 455);
  return libconversion;
}

int ServoSpeed(int maxAngle, int minAngle, int increment){
  int finish = minAngle;
  while (finish != maxAngle){
     angle(finish);
     finish = finish + increment;
  }
}

void initPos(){
      int initPos = angle(90);
    HCPCA9685.Servo(0, initPos);
    HCPCA9685.Servo(1, initPos);
    HCPCA9685.Servo(2, initPos);
    HCPCA9685.Servo(3, initPos);
    HCPCA9685.Servo(4, initPos);
    HCPCA9685.Servo(5, initPos);
    HCPCA9685.Servo(6, initPos);
    HCPCA9685.Servo(7, initPos);
    HCPCA9685.Servo(8, initPos);
    HCPCA9685.Servo(9, initPos);
    HCPCA9685.Servo(10, initPos);
    HCPCA9685.Servo(11, initPos);
}

void setAll(int angle){
    HCPCA9685.Servo(0, angle);
    HCPCA9685.Servo(1, angle);
    HCPCA9685.Servo(2, angle);
    HCPCA9685.Servo(3, angle);
    HCPCA9685.Servo(4, angle);
    HCPCA9685.Servo(5, angle);
    HCPCA9685.Servo(6, angle);
    HCPCA9685.Servo(7, angle);
    HCPCA9685.Servo(8, angle);
    HCPCA9685.Servo(9, angle);
    HCPCA9685.Servo(10, angle);
    HCPCA9685.Servo(11, angle);
}

void leg(int body1, int knee1, int body2, int knee2){
    int a = angle(65);
    int b = angle(115);
    int c = angle(90);
    int d = angle(115);
    
    initPos();
    delay(50);
    HCPCA9685.Servo(knee1, a);
    HCPCA9685.Servo(knee2, d);
    
    HCPCA9685.Servo(body1, b);
    HCPCA9685.Servo(body2, b);
    delay(50);
    HCPCA9685.Servo(body1, c);
    HCPCA9685.Servo(body2, c);
    delay(50);
    //HCPCA9685.Servo(knee1, c);
    //HCPCA9685.Servo(knee2, c);
    //delay(500);
}

void leg2(int body1, int knee1, int body2, int knee2){
    int a = angle(135);
    int b = angle(65);
    int c = angle(90);
    int d = angle(65); 

    initPos();
    delay(50);
    HCPCA9685.Servo(knee1, a);
    HCPCA9685.Servo(knee2, d);
    
    HCPCA9685.Servo(body1, b);
    HCPCA9685.Servo(body2, b);
    delay(50);
    HCPCA9685.Servo(body1, c);
    HCPCA9685.Servo(body2, c);
    delay(50);
    //HCPCA9685.Servo(knee1, c);
    //HCPCA9685.Servo(knee2, c);
    //delay(500);
}

//int main(){
//  initPos(90);
//  
//}
  

void loop(){
    initPos();
    delay(10);
    leg(2, 0, 11, 9);
    delay(10);
    leg2(5, 4, 8, 7);
   
}
