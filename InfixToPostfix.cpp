//
// Created by Arman Sadeghi on 11/7/20.
//

#include "InfixToPostfix.h"
#include "iostream"
#include "stackArray.h"
using namespace std;


void InfixToPostfix::convertToPostFix() {
    stackArray stack(50); // create a stack of 50 elements
    char stackOpr;
    pfx = ""; // initialize postfix
    int length = ifx.length();
    // go through the infix statement
    for (int i = 0; i < length; ++i) {
        if (ifx[i] >= 'A' && ifx[i] <= 'Z') {
            // if its a capital letter
            pfx = pfx + ifx[i]; // add to result (postfix)
        }
        else {
            switch (ifx[i]) {
                case '(':
                    stack.push(ifx[i]);
                    break;
                case ')':
                    stack.top();
                    stack.pop();
                    while (stackOpr != '('){

                    }


            }
        }
    }
}

bool InfixToPostfix::precedence(char opr1, char opr2) {
    int precedence1 = 0, precedence2 = 0;

    if (opr1 == '*' || opr1 == '/'){
        precedence1 = 2;
    }
    else if (opr1 == '+' || opr1 == '-'){
        precedence1 = 1;
    }
    else if (opr1 == '('){
        precedence1 = 0;
    }

    if (opr2 == '*' || opr2 == '/'){
        precedence2 = 2;
    }
    else if (opr2 == '+' || opr2 == '-'){
        precedence2 = 1;
    }
    return (precedence1 >= precedence2);
}

void InfixToPostfix::getInfix(string data) {
    ifx = data;
    convertToPostFix();
}

void InfixToPostfix::showInfix() {
    cout << "inFix: " << ifx << endl;
}

void InfixToPostfix::showPostfix() {
    cout << "PostFix: " << pfx << endl;
}

InfixToPostfix::InfixToPostfix(string infix) {
    ifx = infix;
    convertToPostFix();
}
