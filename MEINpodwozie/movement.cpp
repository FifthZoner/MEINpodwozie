#include <Arduino.h>
#include <math.h>

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
    SetFrontLeftMotor(127);
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
    SetFrontLeftMotor(-127);
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
    SetFrontLeftMotor(127);
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
    SetFrontLeftMotor(-127);
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
    SetFrontLeftMotor(127);
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
    SetFrontLeftMotor(-127);
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
    SetFrontLeftMotor(127);
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
    SetFrontLeftMotor(-127);
    delay(500);
    SetBackRightMotor(0);
    
}

#endif

extern ControllerOutput controllerOutput;

struct MotorValues {
    int fl, fr, bl, br;

    MotorValues(int frontLeft, int frontRight, int backLeft, int backRight) {
        fl = frontLeft;
        fr = frontRight;
        bl = backLeft;
        br = backRight;
    }

    void scaleValue() {
        short max;
        if (fl >= fr and fl >= bl and fl >= br) {
            max = abs(fl);
        }
        else if (fr >= fl and fr >= bl and fr >= br) {
            max = abs(fr);
        }
        else if (bl >= fl and bl >= fr and bl >= br) {
            max = abs(bl);
        }
        else if (br >= fl and br >= fr and br >= bl) {
            max = abs(br);
        }
        
        if (max > 255){
            float multiplier = float(max) / 255;
            fl *= multiplier;
            fr *= multiplier;
            bl *= multiplier;
            br *= multiplier;
        }
    }

    MotorValues operator+= (MotorValues const& target){
        fl += target.fl;
        fr += target.fr;
        bl += target.bl;
        br += target.br;
    }

    MotorValues operator* (float value){
        fl *= value;
        fr *= value;
        bl *= value;
        br *= value;
    }

    void apply(){
        SetFrontLeftMotor(fl);
        SetFrontRightMotor(fr);
        SetBackLeftMotor(bl);
        SetBackRightMotor(br);
    }
};


void MoveControllerAngle( void ){

    #ifndef REVERSE_VERTICAL
    MotorValues temp = MotorValues(1, 1, 1, 1);
    temp.fr = temp.fr * controllerOutput.stickVertical * valueForwardSpeedMultiplier;
    temp.fl = temp.fl * controllerOutput.stickVertical * valueForwardSpeedMultiplier;
    temp.br = temp.br * controllerOutput.stickVertical * valueForwardSpeedMultiplier;
    temp.bl = temp.bl * controllerOutput.stickVertical * valueForwardSpeedMultiplier;
    #else
    MotorValues temp = MotorValues(-1, -1, -1, -1) * controllerOutput.stickVertical * valueForwardSpeedMultiplier;
    #endif

    #ifndef REVERSE_HORIZONTAL
    //temp += MotorValues(-1, 1, 1, -1) * float(controllerOutput.stickHorizontal);
    temp.fr = temp.fr + controllerOutput.stickHorizontal;
    temp.fl = temp.fl - controllerOutput.stickHorizontal;
    temp.br = temp.br - controllerOutput.stickHorizontal;
    temp.bl = temp.bl + controllerOutput.stickHorizontal;
    #else
    temp += MotorValues(1, -1, -1, 1) * controllerOutput.stickHorizontal;
    #endif
    
    //temp.scaleValue();

    #ifdef OUTPUT_TO_SERIAL
    Serial.print(temp.fl);
    Serial.print(" ");
    Serial.print(temp.fr);
    Serial.print(" ");
    Serial.print(temp.bl);
    Serial.print(" ");
    Serial.println(temp.br);
    
    #endif

    temp.apply();
}