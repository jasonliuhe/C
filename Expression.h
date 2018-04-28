//
// Created by He Liu on 2018-04-27.
//

#ifndef UNTITLED_EXPRESSION_H
#define UNTITLED_EXPRESSION_H

#include <string>
#include <iostream>
using namespace std;

class Expression {
private:
    Expression* Left;
    Expression* Right;
    Expression* Up;
public:
    Expression();
    Expression(Expression* E, string where);
    Expression(Expression* left, Expression* right);
    void setLeft(Expression* left);
    void setRight(Expression* right);
    void setUp(Expression* up);
    virtual void setValue(string value) = 0;
    Expression* getLeft();
    Expression* getRight();
    virtual string getValue() = 0;
    virtual string getType() = 0;
    virtual int ExecuteInOrder();
    virtual string getInOrderExpression() = 0;
    virtual int ExecutePreOrder()=0;
    virtual string getPreOrderExpression()=0;
    virtual int ExecutePostOrder()=0;
    virtual string getPostOrderExpression()=0;
    virtual ~Expression();
};


#endif //UNTITLED_EXPRESSION_H
