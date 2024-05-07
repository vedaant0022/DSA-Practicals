#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
    int data;
    struct node*next;
}node;

node*front;
node*rear;

void enqueue(int);
int dequeue();
void display();

void main()
{
    int op;
    int val;

    do
    {
        printf("\nPRESS\n1==ENQUEUE\n2==DEQUEUE\n3==DISPLAY\n0==QUITE\n");
        scanf("%d",&op);

        switch (op)
        {
            case 1: printf("Enter data\n");
                    scanf("%d",&val);
                    enqueue(val);
                    break;
            case 2: val=dequeue();
                    break;
            case 3: display();
                    break;
            case 0: break;

            default: printf("Invalid input");
       
        }

    } while (op!=0);
    getch();
    
}

void enqueue(int val)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;

    if(front==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
    printf("%d enqueued successfully",val);
}

int dequeue()
{
    int val=INT_MIN;

    if(front==NULL)
    {
        printf("Queue underflow!!!\n");
       
    }
    else
    {
        node*ptr;
        ptr=front;
        val=front->data;
        front=front->next;
        free(ptr);
        printf("%d Dequeued successfully\n",val);
    }
    return(val);
}

void display()
{
    if(front==NULL)
    {
        printf("Queue underflow");
    }
    else
    {
        node*temp=front;
        printf("\nFRONT<--");

        while (temp!=0)
        {
            printf("-|%d|-",temp->data);
            temp=temp->next;
        }
        printf("-->REAR\n");        

    }
}
