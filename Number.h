//
// Created by He Liu on 2018-04-28.
//

#ifndef UNTITLED_NUMBER_H
#define UNTITLED_NUMBER_H

#include "Expression.h"
#include <string>

class Number : public Expression{
private:
    string Value;
    string Type = "Number";
public:
    Number();
    Number(string value);
    Number(Expression* E, string where, string value);
    Number(Expression* left, Expression* right, string value);
    virtual void setValue(string value);
    virtual string getValue();
    virtual string getType();
    virtual int ExecuteInOrder();
    virtual string getInOrderExpression();
    virtual int ExecutePreOrder();
    virtual string getPreOrderExpression();
    virtual int ExecutePostOrder();
    virtual string getPostOrderExpression();
    virtual ~Number();
};


#endif //UNTITLED_NUMBER_H
