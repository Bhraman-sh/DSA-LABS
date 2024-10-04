#include<iostream>

const int size = 20;

class Stack 
{
public:
    Stack()
    {
        ind = -1;
    }
    void push(int a)
    {
        ind++;
        top = a;
        arr[ind] = a;
    }
private:
    float arr[size];
    int ind;    //to store the index
    int top;    //to store the top element
};