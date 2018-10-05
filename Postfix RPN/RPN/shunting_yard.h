#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

#include "constants.h"
#include "token.h"
#include "integer.h"
#include "double.h"
#include "operators.h"
#include "parenthesis.h"
#include "../../../Includes/Queue/my_queue.h"
#include "../../../Includes/Stack/my_stack.h"
#include "token.h"

class ShuntingYard
{
public:
    ShuntingYard();

    Queue<Token*> get_posfix(Queue<Token*>& infix);


};

#endif // SHUNTING_YARD_H
