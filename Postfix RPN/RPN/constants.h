#ifndef CONSTANTS_H
#define CONSTANTS_H


const int INTEGER = 0;
const int DOUBLE = 1;
const int OPERATORS = 2;
const int VARIABLE = 3;
const int RIGHT_PARENTHESIS = 4;
const int LEFT_PARENTHESIS = 5;


//SFML
const float SCREEN_WIDTH = 1400;
const float SCREEN_HEIGHT = 800;
const float WORK_PANEL = SCREEN_WIDTH*4/5;
const float SIDE_BAR = SCREEN_WIDTH*1/5;


const int SB_MOUSE_POSITION = 0;
const int SB_MOUSE_CLICKED = SB_MOUSE_POSITION + 1;
const int SB_KEY_PRESSED = SB_MOUSE_CLICKED + 1;
const int SB_EQUATION = SB_KEY_PRESSED + 1;

const int HOW_MANY =1400 - SIDE_BAR;

#endif // CONSTANTS_H
