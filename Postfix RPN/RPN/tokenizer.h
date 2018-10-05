#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "../../../Includes/Queue/my_queue.h"
#include "../../../Includes/Stack/my_stack.h"
#include <string>
#include "token.h"

class tokenizer
{
public:
    tokenizer();

    Queue<Token*> tokenizing ( string equation );

};

#endif // TOKENIZER_H
