#ifndef PARENTHESIS_H
#define PARENTHESIS_H

#include <iostream>
#include "constants.h"
#include "token.h"
#include "operators.h"
#include <string>

using namespace std;

//====================================================
//              Right parenthesis
//====================================================
class Right_Parenthesis : public Token
{
public:
    Right_Parenthesis();
    Right_Parenthesis (string value);

    //=== virtual function from parent class
    void Print(ostream& outs) const;
    int TypeOf(){ return RIGHT_PARENTHESIS;}

private:
    string _value;
};

//====================================================
//              Left parenthesis
//====================================================

class Left_Parenthesis : public Token
{
public:
    Left_Parenthesis();
    Left_Parenthesis (string value);

    //=== virtual function from parent class
    void Print(ostream& outs) const;
    int TypeOf(){ return LEFT_PARENTHESIS;}
    int get_preceden() {return 0;} //the preceden of "(" should be smallest

private:
    string _value;
};

#endif // PARENTHESIS_H
