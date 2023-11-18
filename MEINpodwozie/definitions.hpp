// Write ALL the definitions that are hardware dependent here, why english though? Why not?
// Designed for arduino mega, or anyting else with 8 PWM pins + a few input ones

#ifndef DEFINITIONS_HPP
#define DEFINITIONS_HPP

// PWM pins
#define pinFrontLeftForward 2
#define pinFrontLeftBackward 3
#define pinFrontRightForward 4
#define pinFrontRightBackward 5
#define pinBackLeftForward 6
#define pinBackLeftBackward 7
#define pinBackRightForward 8
#define pinBackRightBackward 9

// controller pins
#define pinStickHorizontal 22
#define pinStickVertical 23

#define valueControllerNoise 6

#define valueStickHorizontalUpper 0
#define valueStickHorizontalLower 0
#define valueStickVerticalUpper 0
#define valueStickVerticalLower 0

// control definitions
#define valueForwardSpeedMultiplier 1

// debug definitions, uncomment ones that are not needed
#define OUTPUT_TO_SERIAL
#define DO_NOT_MOVE

#endif