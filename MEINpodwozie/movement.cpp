#include <Arduino.h>

#include "movement.hpp"
#include "motors.hpp"
#include "controller.hpp"

#ifdef MOTOR_IDENTIFICATION

void IdentifyMotors( void ){

    SetFrontLeftMotor(0);
    SetFrontRightMotor(0);
    SetBackLeftMotor(0);
    SetBackRightMotor(0);

    // motors go forward, stop and then backwards

    // front left - 1
    SetFrontLeftMotor(63);
    delay(500);
    SetFrontLeftMotor(127);
    delay(500);
    SetFrontLeftMotor(191);
    delay(500);
    SetFrontLeftMotor(255);
    delay(500);
    SetFrontLeftMotor(0);
    delay(500);
    SetFrontLeftMotor(-63);
    delay(500);
    SetFrontLeftMotor(-127);
    delay(500);
    SetFrontLeftMotor(-192);
    delay(500);
    SetFrontLeftMotor(-255);
    delay(500);
    SetFrontLeftMotor(0);

    // front right - 2
    SetFrontRightMotor(63);
    delay(500);
    SetFrontRightMotor(127);
    delay(500);
    SetFrontRightMotor(191);
    delay(500);
    SetFrontRightMotor(255);
    delay(500);
    SetFrontRightMotor(0);
    delay(500);
    SetFrontRightMotor(-63);
    delay(500);
    SetFrontRightMotor(-127);
    delay(500);
    SetFrontRightMotor(-192);
    delay(500);
    SetFrontRightMotor(-255);
    delay(500);
    SetFrontRightMotor(0);

    // back left - 3
    SetBackLeftMotor(63);
    delay(500);
    SetBackLeftMotor(127);
    delay(500);
    SetBackLeftMotor(191);
    delay(500);
    SetBackLeftMotor(255);
    delay(500);
    SetBackLeftMotor(0);
    delay(500);
    SetBackLeftMotor(-63);
    delay(500);
    SetBackLeftMotor(-127);
    delay(500);
    SetBackLeftMotor(-192);
    delay(500);
    SetBackLeftMotor(-255);
    delay(500);
    SetBackLeftMotor(0);

    // back right - 4
    SetBackRightMotor(63);
    delay(500);
    SetBackRightMotor(127);
    delay(500);
    SetBackRightMotor(191);
    delay(500);
    SetBackRightMotor(255);
    delay(500);
    SetBackRightMotor(0);
    delay(500);
    SetBackRightMotor(-63);
    delay(500);
    SetBackRightMotor(-127);
    delay(500);
    SetBackRightMotor(-192);
    delay(500);
    SetBackRightMotor(-255);
    delay(500);
    SetBackRightMotor(0);
    
}

#endif

extern ControllerOutput controllerOutput;


void MoveControllerAngle( void ){
    
}