#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node*top=NULL;

void push(int);
int pop();
int peek();
void display();

void main()
{
    int op;
    int val;

    do
    {
        printf("\nPRESS\n1==PUSH\n2==POP\n3==PEEK\n4==DISPLAY\n5==QUIT\n");
        scanf("%d",&op);

        switch(op)
        {
            case 1: printf("Enter data");
                    scanf("%d",&val);
                    push(val);
                    break;
            case 2: val = pop();
                    break;
            case 3: val= peek();
                    break;
            case 4: display();
                    break;
            case 5: break;

            default: printf("Invalid Input!!!");

        }
    } while (op!=5);   
}

void push(int val)
{
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=top;
    top=newnode;
    printf("%d Pushed SUccessfully\n",val);

}

int pop()
{
    int val=INT_MIN;

    if(top==NULL)
    {
        printf("Stack Underflow!!!\n");
    }
    else
    {
        node*ptr=top;
        val=top->data;
        top=top->next;
        free(ptr);
        printf("%d Popped successfully",val);
        
    }
    return(val);
}

int peek()
{
    int val = -1;
    if(top==NULL)
    {
        printf("Stack underflow!!!\n");
    }
    else
    {
        val=top->data;
        printf("Top Element: %d",top->data);
    }
    return val;
}

void display()
{
    if(top==NULL)
    {
        printf("Stack underflow!!!!");
    }
    else
    {
        node*temp=top;
        printf("Stack:\n");
        while (temp!=NULL)
        {
            printf("|%d|\n",temp->data);
            temp= temp->next;
        }
        

    }
}
