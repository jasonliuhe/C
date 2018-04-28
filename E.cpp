//
// Created by He Liu on 2018-04-27.
//
#include "Expression.h"
#include "Operator.h"
#include "Number.h"
using namespace std;

int main(){
    Expression* e = new Operator(new Operator(new Number("5"), "R", "-"), new Operator(new Number("4"), new Number("3"),"+"),"*");

    Expression* five = new Number("5");
    Expression* four = new Number("4");
    Expression* three = new Number("3");
    Expression* plus = new Operator(four, three,"+");
    Expression* neg = new Operator(five, "R", "-");
    Expression* mut = new Operator(neg, plus, "*");


    cout << e->getPreOrderExpression() <<endl;
    cout << e->getInOrderExpression() <<endl;
    cout << e->getPostOrderExpression() <<endl;
    return 0;
}
