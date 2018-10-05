#include "parenthesis.h"

//====================================================
//              Right parenthesis
//====================================================

Right_Parenthesis::Right_Parenthesis()
{

}

Right_Parenthesis::Right_Parenthesis(string value) : _value(value) {

}

void Right_Parenthesis::Print(ostream& outs) const{
    outs<<_value;
}




//====================================================
//              Left parenthesis
//====================================================

Left_Parenthesis::Left_Parenthesis(){

}

Left_Parenthesis::Left_Parenthesis(string value) : _value(value) {

}

void Left_Parenthesis::Print(ostream &outs) const{
    outs<<_value;
}
