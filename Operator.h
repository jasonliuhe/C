//
// Created by He Liu on 2018-04-28.
//

#ifndef UNTITLED_OPERATOR_H
#define UNTITLED_OPERATOR_H

#include "Expression.h"
#include <string>

class Operator : public Expression {
private:
    string Value;
    string Type = "Operator";
public:
    Operator();
    Operator(string value);
    Operator(Expression* E, string where, string value);
    Operator(Expression* left, Expression* right, string value);
    virtual void setValue(string value);
    virtual string getValue();
    virtual string getType();
    virtual int ExecuteInOrder();
    virtual string getInOrderExpression();
    virtual int ExecutePreOrder();
    virtual string getPreOrderExpression();
    virtual int ExecutePostOrder();
    virtual string getPostOrderExpression();
    virtual ~Operator();

};


#endif //UNTITLED_OPERATOR_H
