#include "operators.h"

Operators::Operators()
{

}

Operators::Operators( string value) : _value(value){
    if( value == "+" ||
        value == "-" ){
        _preceden = 1;
        _arg = 2;
    }
    else if( value == "*" ||
             value == "/" ){
        _preceden = 2;
        _arg = 2;
    }
    else if( value == "^" ){
        _preceden = 3;
        _arg = 2;
    }
    else if ( value == "sin" ||
              value == "cos" ||
              value == "tan" ||
              value == "csc" ||
              value == "sec" ||
              value == "cot" ){
        _preceden = 4;
        _arg = 1;
    }

}

void Operators::Print(ostream &outs) const{
    outs << _value;
}
