/////////////////////////////////////////////////////////////////
/// switchUtils.h: nintendo switch homebrew-related utilities ///
/////////////////////////////////////////////////////////////////

#ifndef SWITCH_UTILS
#define SWITCH_UTILS

#include <switch.h>

// left joycon button map
#define BUTTON_LZ 8
#define BUTTON_L 6
#define BUTTON_MINUS 11
#define BUTTON_UP_ARROW 13
#define BUTTON_DOWN_ARROW 15
#define BUTTON_LEFT_ARROW 12
#define BUTTON_RIGHT_ARROW 14
#define JOYSTICK_L_UP 13
#define JOYSTICK_L_DOWN 15
#define JOYSTICK_L_LEFT 12
#define JOYSTICK_L_RIGHT 14

// right joycon button map
#define BUTTON_RZ 9
#define BUTTON_R 7
#define BUTTON_PLUS 10
#define BUTTON_X 2
#define BUTTON_B 1
#define BUTTON_Y 3
#define BUTTON_A 0
#define JOYSTICK_R_UP 21
#define JOYSTICK_R_DOWN 23
#define JOYSTICK_R_LEFT 20
#define JOYSTICK_R_RIGHT 22

// nx-link functions (i'm lazy af)
void initNxlink();
void closeNxlink();

#endif
