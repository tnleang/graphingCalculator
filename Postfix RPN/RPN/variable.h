#ifndef VARIABLE_H
#define VARIABLE_H

#include "token.h"
#include <string>

class Variable : public Token
{
public:
    Variable();
    Variable( string var) : _variable(var) {}

    //=== virtual function from parent class
    void Print(ostream& outs) const;
    int TypeOf(){ return VARIABLE;}

private:
    string _variable;
};

#endif // VARIABLE_H
