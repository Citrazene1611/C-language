#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX-1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = value;
        printf("%d pushed\n", value);
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
    {
        printf("%d popped\n", stack[top]);
        top--;
    }
}

void peek()
{
    if(top == -1)
        printf("Stack is empty\n");
    else
        printf("Top = %d\n", stack[top]);
}

void display()
{
    int i;

    if(top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    for(i = top; i >= 0; i--)
        printf("%d ", stack[i]);

    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);

    display();

    peek();
    pop();

    display();

    return 0;
}