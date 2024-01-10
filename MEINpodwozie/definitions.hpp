// Write ALL the definitions that are hardware dependent here, why english though? Why not?
// Designed for arduino mega, or anyting else with 8 PWM pins + a few input ones

#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

// PWM pins
#define pinFrontLeftForward 5
#define pinFrontLeftBackward 4
#define pinFrontRightForward 2
#define pinFrontRightBackward 3
#define pinBackLeftForward 7
#define pinBackLeftBackward 6
#define pinBackRightForward 8
#define pinBackRightBackward 9

// controller pins
#define pinStickHorizontal 22
#define pinStickVertical 23

#define valueControllerNoise 20
#define valueControllerMappedNoise 15

#define valueStickHorizontalUpper 1972
#define valueStickHorizontalLower 978
#define valueStickVerticalUpper 1955
#define valueStickVerticalLower 978

// control definitions
#define valueForwardSpeedMultiplier 1.f

// debug definitions, uncomment ones that are not needed
#define OUTPUT_TO_SERIAL
//#define DO_NOT_MOVE
//#define MOTOR_IDENTIFICATION
//#define REVERSE_VERTICAL
//#define REVERSE_HORIZONTAL

#endif