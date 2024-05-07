#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define max 5

int st[max];
int top = -1;

void push(int);
int pop();
void display(); 

void main()
{
    int op;
    int val;

    do
    {
       printf("\nPress\n1= Push \n2= Pop \n3=Display\n4= Quit\n");
       scanf("%d",&op);

    switch (op){
        case 1: printf("Enter data\n");
                scanf("%d",&val);
                push(val);
                break;

        case 2: val=pop();
                break;

        case 3: display();
                break;

        case 0: break;

        default: printf("Invalid Input");
        
        }
    } while(op!=0);
    
}

void push(int val)
{
    
    if(top == max-1)
    {
        printf("Stack overflow");
    }
    else
    {
        top++;
        st[top]=val;
        printf("%d pushed successfully",val);
    }
}

int pop()
{
    int val = INT_MIN;

    if(top==-1)
    {
        printf("Stack is Empty");

    }
    else
    {
        val = st[top];
        top--;
        printf("%d popped successfully",val);
    }
    return(val);
}

void display()
{
    if(top==-1)
    {
        printf("Stack is Empty");

    }
    else
    {
        int i=top;
        for (int i = top; i >= 0; i--)
        {
            printf("|%d|\n",st[i]);
        }
        
    }
}