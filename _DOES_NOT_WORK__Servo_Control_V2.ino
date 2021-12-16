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
  1   0   2              5   4   3          - Front Leg?
                BODY  
  6   7   8              11   9  10         - Back leg?
  
  
  */

int zero = 90;

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
      int initPos = angle(zero);
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

void steps(int wait){
    int frontLeft[3] = {1, 0, 2};
    int frontRight[3] = {3, 4, 5};
    int backLeft[3] = {6, 7, 8};
    int backRight[3] = {10, 9, 11};
  
    int a = angle(zero-15);
    int b = angle(zero+5);
    int c = angle(zero+15);
    int d = angle(zero-5);

    // Front left, Back Right
    delay(wait);
    HCPCA9685.Servo(frontLeft[2], b);
    HCPCA9685.Servo(backRight[2], b);
    
    HCPCA9685.Servo(frontLeft[1], a);
    HCPCA9685.Servo(backRight[1], c);
  
    delay(wait);
    HCPCA9685.Servo(frontLeft[2], zero);
    HCPCA9685.Servo(backRight[2], zero);
    delay(wait);

    // Front right, Back left
    delay(wait);
    HCPCA9685.Servo(frontRight[2], d);
    HCPCA9685.Servo(backLeft[2], d);
    
    HCPCA9685.Servo(frontRight[1], c);
    HCPCA9685.Servo(backLeft[1], a);
  
    delay(wait);
    HCPCA9685.Servo(frontRight[2], zero);
    HCPCA9685.Servo(backLeft[2], zero);
    delay(wait);

} 

void loop(){
    initPos();
    delay(10);
    steps(1000);
   
}
