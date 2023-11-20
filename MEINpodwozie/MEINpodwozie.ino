#include "definitions.hpp"
#include "controller.hpp"
#include "movement.hpp"

void setup() {
  pinMode(pinFrontLeftForward, OUTPUT);
  pinMode(pinFrontLeftBackward, OUTPUT);
  pinMode(pinFrontRightForward, OUTPUT);
  pinMode(pinFrontRightBackward, OUTPUT);
  pinMode(pinBackLeftForward, OUTPUT);
  pinMode(pinBackLeftBackward, OUTPUT);
  pinMode(pinBackRightForward, OUTPUT);
  pinMode(pinBackRightBackward, OUTPUT);
  pinMode(pinStickHorizontal, INPUT);
  pinMode(pinStickVertical, INPUT);

  #ifdef OUTPUT_TO_SERIAL
  Serial.begin(9600);
  #endif
}

void loop() {

  UpdateController();

  #ifdef MOTOR_IDENTIFICATION

  IdentifyMotors();

  #else

  MoveControllerAngle();

  #endif

  
}
