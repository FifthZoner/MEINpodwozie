#include "controller.hpp"
#include "definitions.hpp"
#include <Arduino.h>

ControllerOutput controllerOutput;

void GetStickOutput( void ){
    int vertical = map(pulseIn(pinStickVertical, HIGH), valueStickVerticalLower - valueControllerNoise, 
    valueStickVerticalUpper + valueControllerNoise, 0, 510) - 255;
    int horizontal = map(pulseIn(pinStickHorizontal, HIGH), valueStickHorizontalLower - valueControllerNoise, 
    valueStickHorizontalUpper + valueControllerNoise, 0, 510) - 255;
    #ifdef OUTPUT_TO_SERIAL
    Serial.print("Vertical stick: ");
    Serial.print(vertical);
    Serial.print(" Horizontal stick: ");
    Serial.println(horizontal);
    #endif
}

void UpdateController( void ){
    GetStickOutput();
}