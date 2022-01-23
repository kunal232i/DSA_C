#include<stdio.h>
#include <stdlib.h>
#define MAX 100


int stack[MAX];
int top=-1;
int num;
void push();
void pop();

int main()
{
    printf("Enter the binary number: ");
    scanf("%d",&num);
    push();
    pop();
}
void push()
{
  int dec_value = 0;
        int base = 1;
        int temp = num;
        while(temp)
        {
            int last_digit = temp % 10;
            temp = temp / 10;
            dec_value += last_digit * base;
            base = base * 2;
                
        if(top>=MAX)
        {
            printf("\nSTACK OVERFLOW!");
        }
        else
        {
            top++;
            stack[top]=dec_value;
        }
    }
}
void pop()
{
    printf("Its decimal form: ");
    printf("%d",stack[top]);
    if(top<0)
    {
        printf("\nStack is empty!");
    }
}



