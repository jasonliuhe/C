//
// Created by He Liu on 2018-04-27.
//

#include "Expression.h"

Expression::Expression() {
    Left = NULL;
    Right = NULL;
    Up = NULL;
}


Expression::Expression(Expression *E, string where) {
    if (where == "L"){
        setLeft(E);
        Right == NULL;

    } else {
        setRight(E);
        Left = NULL;
    }
}

Expression::Expression(Expression *left, Expression *right) {
    setLeft(left);
    setRight(right);
}

void Expression::setLeft(Expression *left) {
    Left = left;
    Left->setUp(this);
}

void Expression::setRight(Expression *right) {
    Right = right;
    Right->setUp(this);
}

void Expression::setUp(Expression *up) {
    Up = up;
}

Expression* Expression::getLeft() {
    return Left;
}

Expression* Expression::getRight() {
    return Right;
}

int Expression::ExecuteInOrder(){

    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!Left && !Right)
    {
        if (getType() == "N")
        {
            return stoi(getValue());
        } else {
            cout << "Error: Operator cannot at the end of the tree." <<endl;
            exit(2);
        }
    } else if (Left && !Right)
    {
        if (getType() == "N")
        {
            cout << "Error: Number must at the end of the tree." <<endl;
            exit(1);
        } else {
            cout << "Error: The Operator always has a Expression on it right side." << endl;
            exit(4);
        }
    } else if (!Left && Right){
        if (getType() == "O" && getValue() == "-")
        {

            return Right->ExecuteInOrder()-2*Right->ExecuteInOrder();
        } else {
            cout << "Error: The number cannot have child." << endl;
            exit(5);
        }
    } else if (Left && Right){
        if (getType() == "O"){
            if (getValue() == "+")
            {
                return Left->ExecuteInOrder() + Right->ExecuteInOrder();
            } else if (getValue() == "-") {
                return Left->ExecuteInOrder() - Right->ExecuteInOrder();
            } else if (getValue() == "*") {
                return Left->ExecuteInOrder() * Right->ExecuteInOrder();
            } else if (getValue() == "/") {
                return Left->ExecuteInOrder() / Right->ExecuteInOrder();
            } else {
                cout << "Error: invalid operator" << endl;
                exit(7);
            }
        } else {
            cout << "Error: The Number cannot have child." << endl;
            exit(6);
        }
    }
    return 0;
}

Expression::~Expression() {
    delete Left;
    delete Right;
    delete Up;
}

