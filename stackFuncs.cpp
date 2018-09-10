#include <iostream>
#include "MyStack.h"

using namespace std;

void Stack::push(int element)
{
    myStack[++currentPosition] = element;
}

int Stack::pop()
{
    if (currentPosition != -1)return myStack[currentPosition--];
    else return -1;
}

int Stack::getFirst()
{
    if (currentPosition > -1) return myStack[0];
    else return -1;
}

void Stack::showStack()
{
    for (int i = 0; i <= currentPosition; i++) cout << myStack[i] << " ";
    cout << "\n\n";
}

