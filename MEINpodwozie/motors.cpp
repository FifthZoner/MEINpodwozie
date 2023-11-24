#include <Arduino.h>

#include "motors.hpp"
#include "definitions.hpp"

#ifndef USE_PWM_NOISE

void SetFrontLeftMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < 0){
        analogWrite(pinFrontLeftForward, 0);
        analogWrite(pinFrontLeftBackward, -value);
    }
    else if (value > 0){
        analogWrite(pinFrontLeftForward, value);
        analogWrite(pinFrontLeftBackward, 0);
    }
    else {
        analogWrite(pinFrontLeftForward, 0);
        analogWrite(pinFrontLeftBackward, 0);
    }

    #endif
}

void SetFrontRightMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < 0){
        analogWrite(pinFrontRightForward, 0);
        analogWrite(pinFrontRightBackward, -value);
    }
    else if (value > 0){
        analogWrite(pinFrontRightForward, value);
        analogWrite(pinFrontRightBackward, 0);
    }
    else {
        analogWrite(pinFrontRightForward, 0);
        analogWrite(pinFrontRightBackward, 0);
    }

    #endif
}

void SetBackLeftMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < 0){
        analogWrite(pinBackLeftForward, 0);
        analogWrite(pinBackLeftBackward, -value);
    }
    else if (value > 0){
        analogWrite(pinBackLeftForward, value);
        analogWrite(pinBackLeftBackward, 0);
    }
    else {
        analogWrite(pinBackLeftForward, 0);
        analogWrite(pinBackLeftBackward, 0);
    }

    #endif
}

void SetBackRightMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < 0){
        analogWrite(pinBackRightForward, 0);
        analogWrite(pinBackRightBackward, -value);
    }
    else if (value > 0){
        analogWrite(pinBackRightForward, value);
        analogWrite(pinBackRightBackward, 0);
    }
    else {
        analogWrite(pinBackRightForward, 0);
        analogWrite(pinBackRightBackward, 0);
    }

    #endif
}

#else

void SetFrontLeftMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < -valueControllerMappedNoise){
        analogWrite(pinFrontLeftForward, 0);
        analogWrite(pinFrontLeftBackward, -value);
    }
    else if (value > valueControllerMappedNoise){
        analogWrite(pinFrontLeftForward, value);
        analogWrite(pinFrontLeftBackward, 0);
    }
    else {
        analogWrite(pinFrontLeftForward, 0);
        analogWrite(pinFrontLeftBackward, 0);
    }

    #endif
}

void SetFrontRightMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < -valueControllerMappedNoise){
        analogWrite(pinFrontRightForward, 0);
        analogWrite(pinFrontRightBackward, -value);
    }
    else if (value > valueControllerMappedNoise){
        analogWrite(pinFrontRightForward, value);
        analogWrite(pinFrontRightBackward, 0);
    }
    else {
        analogWrite(pinFrontRightForward, 0);
        analogWrite(pinFrontRightBackward, 0);
    }

    #endif
}

void SetBackLeftMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < -valueControllerMappedNoise){
        analogWrite(pinBackLeftForward, 0);
        analogWrite(pinBackLeftBackward, -value);
    }
    else if (value > valueControllerMappedNoise){
        analogWrite(pinBackLeftForward, value);
        analogWrite(pinBackLeftBackward, 0);
    }
    else {
        analogWrite(pinBackLeftForward, 0);
        analogWrite(pinBackLeftBackward, 0);
    }

    #endif
}

void SetBackRightMotor(int value){

    #ifndef DO_NOT_MOVE

    if (value < -valueControllerMappedNoise){
        analogWrite(pinBackRightForward, 0);
        analogWrite(pinBackRightBackward, -value);
    }
    else if (value > valueControllerMappedNoise){
        analogWrite(pinBackRightForward, value);
        analogWrite(pinBackRightBackward, 0);
    }
    else {
        analogWrite(pinBackRightForward, 0);
        analogWrite(pinBackRightBackward, 0);
    }

    #endif
}

#endif