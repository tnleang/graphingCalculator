#include "token.h"

Token::Token()
{

}

ostream& operator <<(ostream& outs, const Token& token){
    token.Print(outs);
    return outs;
}

void Token::Print(ostream &outs) const{
    cout << "TOKEN Print: I should not be called" << endl;
    //empty
}

int Token::get_preceden(){
    cout << "TOKEN get_preceden: I should not be called"  << endl;
    //empty
}
