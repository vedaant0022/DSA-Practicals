#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node{
    int data;
    struct node*next;
    struct node*prev;
}node;

node*start=NULL;

void createLL();
void insertbeg(int);
void insertend(int);
int delete();
int deleteend();
void display();

void main()
{
    int op;
    int val;

    do{
        printf("\nPRESS\n1==CREATE\n2==INSERT@BEG\n3==INSERT@END\n4==DELETE@BEG\n5==DELETE@END\n6==DISPLAY\n7==QUIT\n");
        scanf("%d",&op);

        switch(op){

            case 1: createLL();
                    break;
            case 2: printf("Enter data\n");
                    scanf("%d",&val);
                    insertbeg(val);
                    break;
            case 3: printf("Enter data\n");
                    scanf("%d",&val);
                    insertend(val);
                    break;
            case 4: val=delete();
                    break;
            case 5: val=deleteend();
                    break;
            case 6: display();
                    break;
            case 7: break;

            default: printf("Invalid input!!!\n");
        }
    }while(op!=7);
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
        printf("Linkedlist already exist\n");
    }
    else
    {
        printf("Enter number of nodes you want\n");
        scanf("%d",&n);
        printf("Enter data one by one\n");

        for (int i = 1; i <= n; i++)
        {
            scanf("%d",&val);
            node*newnode=(node*)malloc(sizeof(node));
            newnode->data=val;
            newnode->next=NULL;

            if(start==NULL)
            {
                newnode->prev=NULL;
                start=newnode;
                ptr=start;
            }
            else
            {
                ptr->next=newnode;
                newnode->prev=ptr;
                ptr=ptr->next;
            }
           
        }  
         printf("Linkedlist created successfully\n");    
    }
}

void insertbeg(int val)
{
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->prev=NULL;
    newnode->next=start;

    if(start!=NULL)
    {
        start->prev=newnode;
    }
    start=newnode;

    printf("%d insert beginning",val);
}

void insertend(int val)
{
    
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;

    if(start==NULL)
    {
        newnode->prev=NULL;
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
        newnode->prev=ptr;

    }   
    printf("%d inserted ait end",val);

}

int delete()
{
    int val=INT_MIN;

    if(start==NULL)
    {
        printf("Linkedlist empty");
    }
    else
    {
      node*ptr;
      ptr=start;
      val = start->data;

      if(start!=NULL)
      {
        start->prev=NULL;
      }  
      free(ptr);
      printf("%d deleted successfully",val);
    }
    return(val);
}

int deleteend()
{
    int val= INT_MIN;
    if(start==NULL)
    {
        printf("Linkedlist empty");
    }
    else
    {
        node*ptr;
        node*preptr;
        ptr=start;

        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        val = ptr->data;
        if(ptr==start)
        {
            start=NULL;
        }
        else
        {
            preptr=ptr->prev;
            preptr->next=NULL;
        }
        free(ptr);
        printf("%d deleted at end\n",val);
    }
    return(val);
}

void display()
{
    if(start==NULL)
    {
        printf("Linkedlist empty");
    }
    else
    {
        node*temp=start;

        while (temp!=NULL)
        {
            printf("-|%d|-",temp->data);
            temp=temp->next;
        }
        printf("\n");        

    }
}