#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include "constants.h"

using namespace std;

class Token
{
public:
    Token();
    friend ostream& operator <<(ostream& outs, const Token& token);

    // should not be called
    virtual void Print(ostream& outs) const;
    virtual int TypeOf(){}
    virtual int get_preceden();

};

#endif // TOKEN_H
