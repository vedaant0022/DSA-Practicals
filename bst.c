#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<limits.h>
#define max 50

typedef struct node{
    int data;
    struct node*left;
    struct node*right;
}node;

node *getnode(int);
node *insert(int ,node*);
node *delete(int,node*);
void inorder(node*);
void preorder(node*);
void postorder(node*);

void main()
{
    node*root=NULL;
    int op;
    int val;

    do{
        printf("\nPRESS\n1==INSERT\n2==DELETE\n3==DISPLAY\n4==QUIT\n");
        scanf("%d",&op);

        switch (op)
        {
            case 1: printf("Enter data to be insert\n");
                    scanf("%d",&val);
                    root=insert(val,root);
                    break;
            case 2: printf("Enter data to be deleted\n");
                    scanf("%d",&val);
                    root=delete(val,root);
                    break;
            case 3: printf("Inorder\n");
                    root(inorder);
                    printf("Preorder\n");
                    root(preorder);
                    printf("Postorder\n");
                    root(postorder);
            case 4: break;
        }while(op!=4);
    }
    getch();
}

node *getnode(int val, node*root)
{
    node*newnode;
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    return(newnode);    
}

node*insert(int val, node*root)
{
    if(root==NULL)
    {
        return(getnode(val));
    }
    else
    {
        if(val<root->data)
        {
            root->left=insert(val, root->left);
        }
        else
        {
            root->right=insert(val, root->right);
        }
        return(root);
    }
}

node *delete(int val, node*root)
{
    if(root==NULL)
    {
        printf("%d Node not found",val);
        return(root);
    }
    else
    {
        if(val<root->data)
        {
            root->left=delete(int val,root->left);            
        }
        else if(val>root->data)
        {
            root->right=delete(int val,root->right);
        }
        else
        {
            node*temp;

            if(root->left==NULL)
            {
                temp=root->right;
                free(root);
                return(root);
            }
            else if(root->right==NULL)
            {
                temp=root->left;
                free(root);
                return(root);
            }
            else
            {
                temp=root->left;
                while(temp->right!=NULL)
                {
                    temp=temp->right;
                    root->data=temp->data;
                    root->left=delete(root->left,temp->data)
                }                
            }

        }
        return(root);

    }
}

void inorder(node*root)
{
    if(root!=NULL)
    inorder(root->left);
    printf("%d",root->data);
    inorder(root->right);
}

void preorder(node*root)
{
    if(root!=NULL)
    printf("%d",root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root)
{
    if(root!=NULL)
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->data);
}