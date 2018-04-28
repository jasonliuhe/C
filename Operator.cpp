//
// Created by He Liu on 2018-04-28.
//

#include "Operator.h"

Operator::Operator() : Expression(){
    Value = "";
}

Operator::Operator(string value) : Expression(){
    Value = value;
}

Operator::Operator(Expression *E, string where, string value) : Expression(E, where){
    Value = value;
}

Operator::Operator(Expression *left, Expression *right, string value) : Expression(left, right){
    Value = value;
}

void Operator::setValue(string value) {
    Value = value;
}

string Operator::getValue() {
    return Value;
}

string Operator::getType() {
    return Type;
}

int Operator::ExecuteInOrder(){

    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight())
    {
        cout << "Error: Operator cannot at the end of the tree." <<endl;
        exit(2);
    } else if (getLeft() && !getRight())
    {

        cout << "Error: The Operator always has a Expression on it right side." << endl;
        exit(4);
    } else if (!getLeft() && getRight()){
        if (getValue() == "-")
        {
            return getRight()->ExecuteInOrder()-2*getRight()->ExecuteInOrder();
        } else {
            cout << "Error: The Operator cannot before Number except -." << endl;
            exit(5);
        }
    } else if (getLeft() && getRight()){
        if (getValue() == "+")
        {
            return getLeft()->ExecuteInOrder() + getRight()->ExecuteInOrder();
        } else if (getValue() == "-") {
            return getLeft()->ExecuteInOrder() - getRight()->ExecuteInOrder();
        } else if (getValue() == "*") {
            return getLeft()->ExecuteInOrder() * getRight()->ExecuteInOrder();
        } else if (getValue() == "/") {
            return getLeft()->ExecuteInOrder() / getRight()->ExecuteInOrder();
        } else {
            cout << "Error: invalid operator" << endl;
            exit(7);
        }
    }
}

string Operator::getInOrderExpression() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight())
    {
        cout << "Error: Operator cannot at the end of the tree." <<endl;
        exit(2);
    } else if (getLeft() && !getRight())
    {

        cout << "Error: The Operator always has a Expression on it right side." << endl;
        exit(4);
    } else if (!getLeft() && getRight()){
        if (getValue() == "-")
        {
            return "-"+getRight()->getInOrderExpression()+"";
        } else {
            cout << "Error: The Operator cannot before Number except -." << endl;
            exit(5);
        }
    } else if (getLeft() && getRight()){
        if (getValue() == "+")
        {
            return  getLeft()->getInOrderExpression() + "+" + getRight()->getInOrderExpression();
        } else if (getValue() == "-") {
            return getLeft()->getInOrderExpression() + "-" + getRight()->getInOrderExpression();
        } else if (getValue() == "*") {
            return getLeft()->getInOrderExpression() + "*" + getRight()->getInOrderExpression();
        } else if (getValue() == "/") {
            return getLeft()->getInOrderExpression() + "/" + getRight()->getInOrderExpression();
        } else {
            cout << "Error: invalid operator" << endl;
            exit(7);
        }
    }
}

int Operator::ExecutePreOrder() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight())
    {
        cout << "Error: Operator cannot at the end of the tree." <<endl;
        exit(2);
    } else if (getLeft() && !getRight())
    {
        if (getValue() == "-")
        {
            return getLeft()->ExecutePreOrder()-2*getLeft()->ExecutePreOrder();
        } else {
            cout << "Error: The Operator cannot before Number except -." << endl;
            exit(5);
        }
    } else if (!getLeft() && getRight()){
        if (getValue() == "-")
        {
            return getRight()->ExecutePreOrder()-2*getRight()->ExecutePreOrder();
        } else {
            cout << "Error: The Operator cannot before Number except -." << endl;
            exit(5);
        }
    } else if (getLeft() && getRight()){
        if (getValue() == "+") {
            return getLeft()->ExecutePreOrder() + getRight()->ExecutePreOrder();
        } else if (getValue() == "-") {
            return getLeft()->ExecutePreOrder() - getRight()->ExecutePreOrder();
        } else if (getValue() == "*") {
            return getLeft()->ExecutePreOrder() * getRight()->ExecutePreOrder();
        } else if (getValue() == "/") {
            return getLeft()->ExecutePreOrder() / getRight()->ExecutePreOrder();
        } else {
            cout << "Error: invalid operator" << endl;
            exit(7);
        }
    }
}

string Operator::getPreOrderExpression() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight()) {
        return Value;
    } else if (getLeft() && !getRight()) {
        return Value + getLeft()->getPreOrderExpression();
    } else if (!getLeft() && getRight()){
            return Value+getRight()->getPreOrderExpression();
    } else if (getLeft() && getRight()){
        return Value + getLeft()->getPreOrderExpression() + getRight()->getPreOrderExpression();
    }
    exit(11);
}

int Operator::ExecutePostOrder() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight())
    {
        cout << "Error: Operator cannot at the end of the tree." <<endl;
        exit(2);
    } else if (getLeft() && !getRight())
    {
        if (getValue() == "-")
        {
            return getLeft()->ExecutePostOrder()-2*getLeft()->ExecutePostOrder();
        } else {
            cout << "Error: The Operator cannot before Number except -." << endl;
            exit(5);
        }
    } else if (!getLeft() && getRight()){
        if (getValue() == "-")
        {
            return getRight()->ExecutePostOrder()-2*getRight()->ExecutePostOrder();
        } else {
            cout << "Error: The Operator cannot before Number except -." << endl;
            exit(5);
        }
    } else if (getLeft() && getRight()){
        if (getValue() == "+") {
            return getLeft()->ExecutePostOrder() + getRight()->ExecutePostOrder();
        } else if (getValue() == "-") {
            return getLeft()->ExecutePostOrder() - getRight()->ExecutePostOrder();
        } else if (getValue() == "*") {
            return getLeft()->ExecutePostOrder() * getRight()->ExecutePostOrder();
        } else if (getValue() == "/") {
            return getLeft()->ExecutePostOrder() / getRight()->ExecutePostOrder();
        } else {
            cout << "Error: invalid operator" << endl;
            exit(7);
        }
    }
}

string Operator::getPostOrderExpression() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight()) {
        return Value;
    } else if (getLeft() && !getRight()) {
        return getLeft()->getPostOrderExpression() + Value;
    } else if (!getLeft() && getRight()){
        return getRight()->getPostOrderExpression() + Value;
    } else if (getLeft() && getRight()){
        return getLeft()->getPostOrderExpression() + getRight()->getPostOrderExpression() + Value;
    }
    exit(11);
}

Operator::~Operator() {
}