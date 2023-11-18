#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

struct ControllerOutput {
    int stickVertical = 0;
    int stickHorizontal = 0;
};

void UpdateController( void );

#endif