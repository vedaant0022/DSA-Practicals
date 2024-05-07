#include<stdio.h>

void main()
{
    int n;
    int key;
    int flag = 0 ;
    int arr[n];
    int i;
    printf("Enter number of input needed\n");
    scanf("%d", &n);

    
    
    printf("Enter data one by one\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter number to be searched\n");
    scanf("%d",&key);

     for (i = 0; i < n ; i++)
    {
        if (key == arr[i] )
        {
            flag = 1;
            break;
        }
    }

    if (flag == 1)
    {
        printf("we got the element at index %d",i);
    }
    else
    {
        printf("we have'nt got element at any index in the array\n");
    }
}
