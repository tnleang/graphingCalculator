#include "variable.h"


Variable::Variable()
{

}

void Variable::Print(ostream& outs) const{
    outs << _variable;
}
