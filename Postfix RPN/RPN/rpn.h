#ifndef RPN_H
#define RPN_H

#include "token.h"
#include "integer.h"
#include "double.h"
#include "operators.h"
#include "parenthesis.h"
#include "../../../Includes/Queue/my_queue.h"
#include "../../../Includes/Stack/my_stack.h"

#include <cmath>

class RPN
{
public:
    RPN();

    //double _get_result();
    double _get_result(const Queue<Token *>& equation, const double &value);


private:
    double _get_answer( Stack<double>& stack, Token* operate);
    // return the individual calculation

};



#endif // RPN_H
