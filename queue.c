#include<stdio.h>
#include<conio.h>
#include<limits.h>
#define max 5

int qu[max];
int front =-1;
int rear = -1;

void enqueue(int);
int dequeue();
void display();

void main()
{
    int op;
    int val;

    do
    {
        printf("\nPRESS\n1==ENQUEUE\n2==DEQUEUE\n3==DISPLAY\n");
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
    if(rear==max-1)
    {
        printf("Queue is empty");
    }
    else
    {
        if (front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else
        {
            rear++;
        }
        qu[rear]=val;

        printf("%d Enqueued Successfully",val);
    }
}

int dequeue()
{
    int val = INT_MIN;

    if(front==-1 && rear==-1)
    {
        printf("Queue underflow");
    }
    else
    {
        val = qu[front];

        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front--;
        }
        printf("%d dequeued successfully",val);
    }
    return(val);
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue underflow!!!!!!\n");

    }
    else
    {
        int i;
        printf("\nFront<---");
        for (int i = front; i <= rear; i++)
        {
            printf("--|%d|--",qu[i]);
        }  
        printf("--->Rear\n");
    }
}


  

