#include "controller.hpp"
#include "definitions.hpp"
#include <Arduino.h>

ControllerOutput controllerOutput;

void GetStickOutput( void ){
    controllerOutput.stickVertical = map(pulseIn(pinStickVertical, HIGH), valueStickVerticalLower - valueControllerNoise, 
    valueStickVerticalUpper + valueControllerNoise, 0, 510) - 255;
    controllerOutput.stickHorizontal = map(pulseIn(pinStickHorizontal, HIGH), valueStickHorizontalLower - valueControllerNoise, 
    valueStickHorizontalUpper + valueControllerNoise, 0, 510) - 255;
    #ifdef OUTPUT_TO_SERIAL
    //delay(500);
    //Serial.print("Vertical stick: ");
    //Serial.print(controllerOutput.stickVertical);
    //Serial.print(", horizontal stick: ");
    //Serial.println(controllerOutput.stickHorizontal);
    //Serial.print("Raw vertical: ");
    //Serial.print(pulseIn(pinStickVertical, HIGH));
    //Serial.print(", raw horizontal: ");
    //Serial.println(pulseIn(pinStickHorizontal, HIGH));
    #endif
}

void UpdateController( void ){
    GetStickOutput();
}