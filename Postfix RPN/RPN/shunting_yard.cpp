#include "shunting_yard.h"



ShuntingYard::ShuntingYard()
{
    //default
}


Queue<Token*> ShuntingYard::get_posfix(Queue<Token *> &infix){
    const bool debug = false;

    /*
     *
     *  if number       -> put into output queue
     *
     *  if operator     -> while incoming one <= the one in stack
     *                     put the one in stack to output queue
     *                     put incoming one to stack if the condition is false
     *
     *  if left "("     -> put into stack
     *
     *  if right ")"    -> pop operator from stack and put into output queue
     *                     until it hit "("
     *
     *
     * */

    //make a copy of the input
    //Queue<Token*> infix = infix;
    Queue<Token*> pos_fix;
    Stack <Token*> op_stack;

    int i= 1;

    while ( !infix.empty() )
    {
        if (debug)
            cout << i++ << endl;

        switch ( infix.front()->TypeOf()){

        // case of the use is number
        // variable is treated as a number
        case INTEGER:
            if (debug){
                cout << "DEBUG: shunting yard: infix.front(): ";
                infix.front()->Print(cout);
                cout << endl;
            }
            pos_fix.push(infix.pop());
            break;
        case DOUBLE:
            if (debug){
                cout << "DEBUG: shunting yard: infix.front(): ";
                infix.front()->Print(cout);
                cout << endl;
            }
            pos_fix.push(infix.pop());
            break;
        case VARIABLE:
            if (debug){
                cout << "DEBUG: shunting yard: infix.front(): ";
                infix.front()->Print(cout);
                cout << endl;
            }

            pos_fix.push(infix.pop());
            break;

        // case of operators
        case OPERATORS:
            if (debug){
                cout << "DEBUG: shunting yard: infix.front(): ";
                infix.front()->Print(cout);
                cout << endl;
            }


            //if empty just push into the stack
            if (op_stack.empty()){
                if (debug){
                    cout << "DEBUG: shunting yard: Push into op stack" << endl;
                }

                op_stack.push(infix.pop());
            }
            else{
                //check the preceden
                //if the new one has smaller or equal then
                //let the old one go to the output queue first
                while( !op_stack.empty() &&
                      infix.front()->get_preceden() <=
                       op_stack.top()->get_preceden()){

                    if (debug){
                        op_stack.top()->Print(cout);
                        cout << " goes first" << endl;
                    }
                    pos_fix.push(op_stack.pop());
                }
                if (debug){
                    infix.front()->Print(cout);
                    cout << " goes into the stack" << endl;
                }
                op_stack.push(infix.pop());
            }
            break;


        // case of parenthesis
        case LEFT_PARENTHESIS:
            if (debug){
                cout << "DEBUG: shunting yard: infix.front(): ";
                infix.front()->Print(cout);
                cout << endl;
                cout << "DEBUG: shunting yard: Push into op stack" << endl;
            }

            //if left paren then just put it into the stack
            op_stack.push(infix.pop());
            break;

        case RIGHT_PARENTHESIS:
            if (debug){
                cout << "DEBUG: shunting yard: infix.front(): ";
                infix.front()->Print(cout);
                cout << endl;
            }

            //if it is right paren
            //pop operator from the stack and put them into the output queue
            //until the pop one is left paren
            infix.pop();
            while( op_stack.top()->TypeOf() != LEFT_PARENTHESIS){


                pos_fix.push(op_stack.pop());
            }
            op_stack.pop();
            break;

        }
    }

    while ( !op_stack.empty() )
    {
        if (debug){
            cout << "DEBUG: shunting yard: push into queue ";
            op_stack.top()->Print(cout);
            cout << endl;
        }
        pos_fix.push(op_stack.pop());
    }

    if (debug){
        cout << pos_fix << endl;
        cout << "DEBUG: shunting yard: end of SY ======="  << endl;
    }


    return pos_fix;

}
