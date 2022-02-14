#include <Arduino.h>
#include "Renard.h"
#include "Servo.h"
/*
// Renard protocol baud rate.
const int BAUDRATE = 57600;

// Renard channels.
const int TOTAL_CHANNELS = 8;
const int HEAD_CHANNEL = 3;
const int JAW_CHANNEL = 1;
const int EYES_CHANNEL = 2;

// Pins
const int HEAD_SERVO_PIN = 8;
const int JAW_SERVO_PIN = 7;
const int EYES_PWM_PIN = 3;

// Ranges of servos.
const int HEAD_SERVO_LEFT = 0;
const int HEAD_SERVO_RIGHT = 180;
const int HEAD_SERVO_CENTER = 90;
const int JAW_SERVO_CLOSED = 60;
const int JAW_SERVO_OPEN = 102;

Servo headServo;
Servo jawServo;
Renard renard(Serial, TOTAL_CHANNELS);

void setup()
{
  Serial.begin(BAUDRATE);
  headServo.attach(HEAD_SERVO_PIN);
  headServo.write(45);

  jawServo.attach(JAW_SERVO_PIN);
  jawServo.write(JAW_SERVO_OPEN);
  pinMode(EYES_PWM_PIN, OUTPUT);

  analogWrite(EYES_PWM_PIN, 255);
}

void loop()
{

  while (!renard.processInput())
    ;

  int headValue = renard.channelValue(HEAD_CHANNEL);
  if (headValue == 0)
  {
    headServo.write(HEAD_SERVO_CENTER);
  }
  else
  {
    headServo.write(map(headValue, 1, 255, HEAD_SERVO_LEFT, HEAD_SERVO_RIGHT));
  }

  int jawValue = renard.channelValue(JAW_CHANNEL);
  jawServo.write(map(jawValue, 0, 255, JAW_SERVO_CLOSED, JAW_SERVO_OPEN));

  int eyesValue = renard.channelValue(EYES_CHANNEL);
  analogWrite(EYES_PWM_PIN, eyesValue);
}
*/


/*
   Yellow: Pin 9
   Red: +5V
   Brown: GND
*/

//****** NEW BOOTLOADER *******

// Values on the servo that correspond to mouth positions.
const int FULLOPEN = 102;
const int FULLCLOSED = 60;

const int SERVO_MOUTH_PIN = 7;
const int SERVO_HEAD_PIN = 8;
const int EYES_PIN = 3;

Servo servoMouth;
Servo servoHead;
Servo servoEyes;
Renard renard(Serial, 3);

//Reverse left and right on the skeleton, useful for when the parrot is on his right sholder. If so, make it true
const boolean reverseLeftAndRightHead = true;

void setup() {
  // Open serial communications
  Serial.begin(57600);
  pinMode(EYES_PIN, OUTPUT);

  servoMouth.attach(SERVO_MOUTH_PIN);
  servoMouth.write(FULLCLOSED);
  servoHead.attach(SERVO_HEAD_PIN);
  servoHead.write(45);
  analogWrite(EYES_PIN, 255);
}

void loop() {
  // Read renard
  while (!renard.processInput())
    ;

  //Do Mouth
  int channelValueMouth = renard.channelValue(1);
  int posMouth = map(channelValueMouth, 0, 255, FULLCLOSED, FULLOPEN);
  servoMouth.write(posMouth);

  //Do Eyes
  int eyesValue = renard.channelValue(2);
  analogWrite(EYES_PIN, eyesValue);

  

  //Do Head
  int channelValueHead = renard.channelValue(3);
  int headPos = 90;
  if (channelValueHead != 0) {
    if(reverseLeftAndRightHead){
        headPos = map(channelValueHead, 0, 255, 180, 0);
    }
    else {
        headPos = map(channelValueHead, 0, 255, 0, 180);
    }
    
  }
  servoHead.write(headPos);

}