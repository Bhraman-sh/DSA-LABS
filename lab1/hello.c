#include<stdio.h>
#include"stack.h"

int main()
{
    STACK s;
    initStack(&s);
    push(&s, 7);

    printf("Hello: %d", pop(&s));
}