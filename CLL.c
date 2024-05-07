#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
    int data;
    struct node*next;
}node;

node*start=NULL;

void createLL();
void insertbeg(int);
void insertEnd(int);
int deleteBeg();
int deleteEnd();
void display();

void main()
{
    int op;
    int val;

    do{
        printf("\nPRESS\n1==CREATE\n2==INSERTBEG\n3==INSERTEND\n4==DELETE\n5==DELETEEND\n6==DISPLAY\n7==QUIT\n");
        scanf("%d",&op);

        switch (op)
        {
            case 1: createLL();
                    break;
            case 2: printf("Enter data\n");
                    scanf("%d",&val);
                    insertbeg(val);
                    break;
            case 3: printf("Enter data\n");
                    scanf("%d",val);
                    insertEnd(val);
                    break;
            case 4: val = deleteBeg();
                    break;
            case 5: val = deleteEnd();
                    break;
            case 6: display();
                    break;
            case 7: break;

            default: printf("Invalid input!!!!!!\n");

        }
    }
}

void createLL()
{
    int n;
    int val;
    int i;
    node*newnode;
    node*ptr;
    
    if(start!=NULL)
    {
        printf("linkedlist already exist\n");
    }
    else
    {
        printf("Enter number of nodes you want\n");
        scanf("%d",&n);
        printf("Enter data one by one\n");

        for(int i = 1; i <= n; i++)
        {
            scanf("%d",&val);
            node*newnode=(node*)malloc(sizeof(node));
            newnode->data=val;

            if(start==NULL)
            {
                newnode->next=newnode;
                start=newnode;
                ptr=start;               
            }
            else
            {
                ptr->next=newnode;
                newnode->next=start;
                ptr=ptr->next;
            }
        }
        printf("Linkedlist created successfully\n");
    }
}

void insertBeg(int val)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=val;

    if(start==NULL)
    {
        newnode->next=newnode;
    }
    else
    {
        node*ptr=start;
        while (ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
}