#include "double.h"

Double::Double()
{

}

Double::Double(string value){
    _value = atof(value.c_str());
}

void Double::Print(ostream &outs) const{
    outs<<_value;
}
