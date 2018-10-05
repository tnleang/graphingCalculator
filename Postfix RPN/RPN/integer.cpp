#include "integer.h"

Integer::Integer()
{

}

Integer::Integer(string value){
    _value = atoi(value.c_str());
}

void Integer::Print(ostream& outs) const{
    outs<<_value;
}

