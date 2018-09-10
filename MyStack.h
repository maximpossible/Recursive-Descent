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
//
//void Stack::push(int element);
//int Stack::pop();
//int Stack::getFirst();
//void Stack::showStack();
