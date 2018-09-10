#pragma once

class Stack
{
private:
    short currentPosition = -1;
    int *myStack;
public:
    Stack();
    Stack(int);
    void push(int element);
    int pop();
    void showStack();
    ~Stack();
};
