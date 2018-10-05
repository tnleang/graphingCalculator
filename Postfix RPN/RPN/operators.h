#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>
#include "constants.h"
#include "token.h"
#include <string>



class Operators : public Token
{
public:
    Operators();
    Operators( string value);
    string get_operator() {return _value;}
    int get_preceden() {return _preceden;}

    int how_many_arg() {return _arg;}


    //=== virtual function from parent class
    void Print(ostream& outs) const;
    int TypeOf(){ return OPERATORS;}


private:
    string _value;
    int _arg;
    int _preceden;
};

#endif // OPERATORS_H
