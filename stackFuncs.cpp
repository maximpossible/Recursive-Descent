#include <iostream>
#include "MyStack.h"

using namespace std;

Stack::Stack()
{
    myStack = new int[256];
}

Stack::Stack(int stackSize)
{
    myStack = new int[stackSize];
}

Stack::~Stack()
{
    delete(myStack);
}

void Stack::push(int element)
{
    myStack[++currentPosition] = element;
}

int Stack::pop()
{
    if (currentPosition != -1)return myStack[currentPosition--];
    else return -1;
}

void Stack::showStack()
{
    for (int i = 0; i <= currentPosition; i++) cout << myStack[i] << " ";
    cout << "\n\n";
}

