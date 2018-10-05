#ifndef DOUBLE_H
#define DOUBLE_H

#include "token.h"
#include <string>

class Double : public Token
{
public:
    Double();
    Double( double value ) : _value(value) {}
    Double( string value );

    //=== virtual function from parent class
    void Print(ostream& outs) const;
    int TypeOf(){ return DOUBLE;}
    double get_value(){return _value;}

private:
    double _value;
};

#endif // DOUBLE_H
