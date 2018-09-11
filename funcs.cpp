#include <iostream>
#include <string>
#include <math.h>
#include "MyStack.h"
#include "Funcs.h"

using namespace std;

void replaceAllSymbols(string &str, char findSymb, char replaceSymb)
{
    for (unsigned int i = 0; i < str.length(); i++)
        if (str[i] == findSymb)
            str[i] = replaceSymb;
}

bool isNumber(string lex)
{
    for (unsigned int i = 0; i < lex.length(); i++)
    {
        if (lex[i] == '-' && i == 0) continue;
        if ((lex[i] < '0' || lex[i] > '9')  && lex[i] != '.') return false;
    }
    return true;
}

double calculateExpression(string exp)
{
    string expression = exp;
    double a;
    double b;
    double answer;

    while (expression.rfind(')') != string::npos)
    {
        Stack bracketsStack(20);

        int rightBracket = expression.rfind(')');
        int leftBracket;
        for (int i = rightBracket - 1; i >= 0; i--)
        {
            if (expression[i] == ')') bracketsStack.push(i);
            if (expression[i] == '(' && bracketsStack.pop() != -1) continue;
            if (expression[i] == '(') leftBracket = i;
        }
        string brackets = expression.substr(leftBracket + 1, rightBracket - leftBracket - 1);
        double ans = calculateExpression(brackets);
        expression.replace(leftBracket, brackets.length() + 2, to_string(ans));
    }

    if (isNumber(expression))
    {
        return stof(expression);
    }

    if (expression.rfind('+') != string::npos)
    {
        a = calculateExpression(expression.substr(0, expression.rfind('+')));
        b = calculateExpression(expression.substr(expression.rfind('+') + 1, expression.length() - 1));
        answer = a + b;
    }
    else if (expression.rfind('-') != string::npos)
    {
        a = calculateExpression(expression.substr(0, expression.rfind('-')));
        b = calculateExpression(expression.substr(expression.rfind('-') + 1, expression.length() - 1));
        answer = a - b;
    }
    else if (expression.rfind('*') != string::npos)
    {
        a = calculateExpression(expression.substr(0, expression.rfind('*')));
        b = calculateExpression(expression.substr(expression.rfind('*') + 1, expression.length() - 1));
        answer = a * b;
    }
    else if (expression.rfind('/') != string::npos)
    {
        a = calculateExpression(expression.substr(0, expression.rfind('/')));
        b = calculateExpression(expression.substr(expression.rfind('/') + 1, expression.length() - 1));
        answer = a / b;
    }
    else if (expression.rfind('^') != string::npos)
    {
        a = calculateExpression(expression.substr(0, expression.rfind('^')));
        b = calculateExpression(expression.substr(expression.rfind('^') + 1, expression.length() - 1));
        answer = pow(a, b);
    }
    else if (expression.rfind("sin") != string::npos)
    {
        a = calculateExpression(expression.substr(expression.rfind("sin") + 3, expression.length() - 1));
        answer = sin(a);
    }
    else if (expression.rfind("cos") != string::npos)
    {
        a = calculateExpression(expression.substr(expression.rfind("cos") + 3, expression.length() - 1));
        answer = cos(a);
    }
    return answer;
}


