#ifndef INTEGER_H
#define INTEGER_H

#include "token.h"
#include <string>

class Integer : public Token
{
public:
    Integer();
    Integer( int value ) : _value(value){}
    Integer ( string value ); //case of number given in string

    //=== virtual function from parent class
    void Print(ostream& outs) const;
    int TypeOf(){ return INTEGER;}
    int get_value(){return _value;}

private:
    int _value;
};

#endif // INTEGER_H
