//
// Created by He Liu on 2018-04-28.
//

#include "Number.h"

Number::Number() : Expression(){
    Value = "";
}

Number::Number(string value) : Expression(){
    Value = value;
}

Number::Number(Expression *E, string where, string value) : Expression(E, where){
    Value = value;
}

Number::Number(Expression *left, Expression *right, string value) : Expression(left, right){
    Value = value;
}

void Number::setValue(string value) {
    Value = value;
}

string Number::getValue() {
    return Value;
}

string Number::getType() {
    return Type;
}

int Number::ExecuteInOrder() {

    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight())
    {
        return stoi(getValue());
    } else if (getLeft() && !getRight())
    {
        cout << "Error: Number must at the end of the tree." <<endl;
        exit(1);
    } else if (!getLeft() && getRight()){
        cout << "Error: The number cannot have child." << endl;
        exit(5);
    } else if (getLeft() && getRight()){
        cout << "Error: The Number cannot have child." << endl;
        exit(6);
    }

    exit(10);
}

string Number::getInOrderExpression() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight())
    {
        return Value;
    } else if (getLeft() && !getRight())
    {
        cout << "Error: Number must at the end of the tree." <<endl;
        exit(1);
    } else if (!getLeft() && getRight()){
        cout << "Error: The number cannot have child." << endl;
        exit(5);
    } else if (getLeft() && getRight()){
        cout << "Error: The Number cannot have child." << endl;
        exit(6);
    }
}

int Number::ExecutePreOrder() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight()) {
        return stoi(getValue());
    } else if (getLeft() && !getRight())
    {
        cout << "Error: Number must at the end of the tree." <<endl;
        exit(1);
    } else if (!getLeft() && getRight()){
        cout << "Error: The number cannot have child." << endl;
        exit(5);
    } else if (getLeft() && getRight()){
        cout << "Error: The Number cannot have child." << endl;
        exit(6);
    }

    exit(10);
}

string Number::getPreOrderExpression() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight()) {
        return Value;
    } else if (getLeft() && !getRight()) {
        return getLeft()->getPreOrderExpression() + Value;
    } else if (!getLeft() && getRight()){
        return Value+getRight()->getPreOrderExpression();
    } else if (getLeft() && getRight()){
        return getLeft()->getPreOrderExpression() + Value + getRight()->getPreOrderExpression();
    }
}

int Number::ExecutePostOrder() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight()) {
        return stoi(getValue());
    } else if (getLeft() && !getRight())
    {
        cout << "Error: Number must at the end of the tree." <<endl;
        exit(1);
    } else if (!getLeft() && getRight()){
        cout << "Error: The number cannot have child." << endl;
        exit(5);
    } else if (getLeft() && getRight()){
        cout << "Error: The Number cannot have child." << endl;
        exit(6);
    }

    exit(10);
}

string Number::getPostOrderExpression() {
    if (getValue()==""){
        cout<<"Value is NULL."<<endl;
        exit(3);
    } else if (!getLeft() && !getRight()) {
        return Value;
    } else if (getLeft() && !getRight()) {
        return getLeft()->getPostOrderExpression() + Value;
    } else if (!getLeft() && getRight()){
        return getRight()->getPostOrderExpression()+ Value;
    } else if (getLeft() && getRight()){
        return getLeft()->getPostOrderExpression() + getRight()->getPostOrderExpression() + Value;
    }
}


Number::~Number() {

}