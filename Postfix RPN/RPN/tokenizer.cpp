#include "tokenizer.h"

#include "integer.h"
#include "double.h"
#include "operators.h"
#include "variable.h"
#include "parenthesis.h"

tokenizer::tokenizer()
{

}

Queue<Token*> tokenizer::tokenizing( string equation){
    const bool debug = false;

    /*
     * getline the whole equation
     * look at the string equation individually in each index
     *      if 'x'          -> put into queue
     *      if ( ) + - * /  -> put into queue
     *      if s c t        -> put into queue with 3 index
     *      if digit        -> put digit into temperary string and check the next one
     *                          until the next is not digit, then put the temperary string into queue as number
     *      if white space  -> ignore
     *
     * */

    Queue<Token*> infix;
//    string equation;
//    cout << "Equation: ";
//    getline(cin , equation);

    if (debug){
        cout << "DEBUG: tokenizer: input getline: " << equation << endl;
    }

    int index = 0;
    while ( index < equation.length() ){
        // sub string for the infix queue
        string temp;

        if ( equation[index] == 'x' ){
            if (debug){
                cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
            }

            infix.push(new Variable("x"));
            index++;
        }

        else if (equation[index] == '('){
            if (debug){
                cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
            }

            infix.push(new Left_Parenthesis("("));
            index++;
        }

        else if (equation[index] == ')'){
            if (debug){
                cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
            }

            infix.push(new Right_Parenthesis(")"));
            index++;
        }

        else if( isalpha(equation[index]) ){
            //case if sin cos tan
            if (debug){
                cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
            }

            infix.push(new Operators(equation.substr(index,3)));
            index += 3;
        }

        else if ( isdigit(equation[index]) ){
            //case of number

            if (debug){
                cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
            }

            temp += equation[index];
            index++;
            while ( isdigit(equation[index]) ){
                if (debug){
                    cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
                }

                temp += equation[index];
                index++;
            }

            if (debug){
                cout << "DEBUG: temp: " << temp << endl;
            }
            infix.push(new Double( temp ));
        }

        else if ( isspace(equation[index]) ){
            //if white space, then just ignore
            if (debug){
                cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
            }

            index++;
        }

        else{
            //case of + - * /
            if (debug){
                cout << "DEBUG: equation[" << index <<"]: " << equation[index] << endl;
            }

            temp = equation[index];
            infix.push(new Operators(temp));
            index++;
        }

    }//end of while loop

    if (debug){
        cout << infix << endl;
    }
    return infix;
}
