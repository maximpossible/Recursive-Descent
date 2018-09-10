#pragma once

class Stack
{
private:
    short currentPosition = -1;
    int myStack[256]; //сделать стек динамическим, добавить деструктор
public:
    void push(int element);
    int pop();
    int getFirst();
    void showStack();
};
