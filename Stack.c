#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
#define length 100

char stack[length];
int top = -1;
 
void push(char element)
{
    if(top < length-1)
        stack[++top] = element;
    else
        printf("Stack Overflow, Use bigger stack");
}
 
char pop()
{
    if(top == -1)
        return '\0';
    else
        return stack[top--];
}

bool isFull()
{
    if(top < length - 1)
        return false;
    else
        return true;
}

bool isEmpty()
{
    if(top < 0)
        return true;
    else
        return false;
}

int main(void)
{
    printf("%d\n", isFull());
    printf("%d\n", isEmpty());

    push('5');
    push('7');
    push('1');
    push('a');

    printf("%d\n", isEmpty());

    printf("%c\n", pop());
    printf("%c\n", pop());
    printf("%c\n", pop());
    printf("%c\n", pop());
    printf("%c\n", pop());

}