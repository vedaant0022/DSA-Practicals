#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
    int data;
    struct node*next;
}node;

node*start=NULL;

void createLL();
void insertbeg(int);
void insertend(int);
int deletebeg();
int deleteend();
void display();

void main()
{
    int op;
    int val;

    do{
        printf("\nPRESS\n1=CREATE\n2=INSERTATBEG\n3=INSERTATEND\n4=DELETEATSTART\n5=DELETEATEND\n6=DISPLAY\n7=QUIT\n");
        scanf("%d",&op);

        switch(op)
        {
            case 1: createLL(val);
                    break;
            case 2: printf("Enter data\n");
                    scanf("%d",&val);
                    insertbeg(val);
                    break;
            case 3: printf("Enter data\n");
                    scanf("%d",&val);
                    insertend(val);
                    break;
            case 4: val=deletebeg();
                    break;
            case 5: val=deleteend();
                    break;
            case 6: display();
                    break;
            case 0: break;

            default: printf("Invalid Input!!");
        }
    }while(op!=0);
    getch();
}

void createLL()
{
    int val;
    int n;
    int i;
    node*ptr;
    node*newnode;
    if(start!=NULL)
    {
        printf("LL already exist");
    }
    else
    {
        printf("How many nodes do you want\n");
        scanf("%d",&n);
        printf("Enter data one by one\n");

        for (int i = 1; i <=n; i++)
        {
            scanf("%d",&val);
            node*newnode=(node*)malloc(sizeof(node));
            newnode->data=val;
            newnode->next=NULL;
            if(start==NULL)
            {
                start=newnode;
                ptr=newnode;
            }
            else
            {
                ptr->next=newnode;
                ptr=ptr->next;
            }
        }            
    }
}

void insertbeg(int val)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=start;
    start=newnode;
    printf("%d inserted successfully at beginning",val);
}

void insertend(int val)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        node*ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
    }
    printf("%d inserted successfully at end",val);
}

int deletebeg()
{
    int val=INT_MIN;
    if(start==NULL)
    {
        printf("Linked-list is empty");
    }
    else
    {
        node*ptr;
        node*temp;
        ptr=start;
        val=start->data;
        start=start->next;
        free(ptr);
        printf("%d deleted successfully from start",val);
    }
    return val;
}

int deleteend()
{
    int val=INT_MIN;

    if(start==NULL)
    {
        printf("Linkedlist does not exist");
    }
    else
    {
        node*ptr;
        node*preptr;
        ptr=start;

        while (ptr->next!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        val=ptr->data;

        if(ptr==start)
        {
            start=NULL;
        }
        else
        {
            preptr->next=NULL;
        }
        free(ptr);
        printf("%d deleted successfully",val);       
    }
    return(val);
}

void display()
{
    if(start==NULL)
    {
        printf("dont exist\n");
    }
    else
    {
        node*ptr=start;
       
        while(ptr!=NULL)
        {
            printf("-|%d|-",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
}
