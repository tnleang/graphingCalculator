#include "rpn.h"

RPN::RPN()
{
    //default
}



//===================================================
//===================================================


double RPN::_get_result(const Queue<Token *>& equation, const double &value){
    const bool debug = false;

    /*
     *  while incoming queue is not empty
     *  if number   -> put into the stack
     *  if operator -> pop one number out from the stack
     *                  if the opearator requires to numbers -> pop another one
     *                 do the calculation, then put it back to stack
     *
     *  last, take the leftover number from the stack
     * */

    //the container for the calulator performance
    Stack<double> performance;

    //making a copy of equation first
    //This will allow multiple caculation
    Queue<Token*> postfix = equation;

    int how_many = postfix.size();
    // how many times needed to do the action

    for ( int i =0; i < how_many; i++){
        Token* use = postfix.pop();
        //pop it out
        //then check what it is
        switch( use->TypeOf() ){
        case INTEGER:
            performance.push(static_cast<Integer*>(use)->get_value());
            break;
        case DOUBLE:
            performance.push(static_cast<Double*>(use)->get_value());
            break;
        case VARIABLE:
            performance.push(value);
            break;
        case OPERATORS:
            double answer = _get_answer(performance, use);
            if(debug){
                cout << "DEBUG: RPN: answer: " << answer << endl;
            }
            performance.push( answer );
            break;
        }

    }
    //only one number is expected left inside the stack after all the performances
    double result = performance.pop();
    return result;

}

//===================================================
//
//===================================================




double RPN::_get_answer(Stack<double> &stack, Token *operate){
    //all of the single calculation

        string op =static_cast<Operators*>(operate)->get_operator();
        double a = stack.pop();
        switch (static_cast<Operators*>(operate)->how_many_arg()){

        case 1:
            if (op == "sin")
                return sin(a);
            else if (op == "cos")
                return cos(a);
            else if (op == "tan")
                return tan(a);
            else if (op == "csc")
                return (1/sin(a));
            else if (op == "sec")
                return (1/cos(a));
            else if (op == "cot")
                return (1/tan(a));
            break;

        case 2:
            double b = stack.pop();

            if (op == "+")
                return b + a;
            else if( op == "-")
                return b - a;
            else if( op == "*")
                return b * a;
            else if( op == "/")
                return b / a;
            else if (op == "^")
                return pow( b , a );
            break;

        }
}


