#include<stdio.h>

int main()
{
    int n;
    int arr[n];
    int i;
    int key;
    int first;
    int middle;
    int last;

    printf("Enter number of inputs you want\n");
    scanf("%d",&n);

    printf("Enter data one by one\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nEnter number to searched\n");
    scanf("%d",&key);

    first = 0;
    last = n - 1;
    middle = (first+last)/2;

    while(first <= last)
    {
        if(arr[middle] < key)
        {
            first =  middle + 1;
        }
        else if (arr[middle]==key)
        {
            printf("Found at location %d",middle+1);
            break;
        }
        else
        {
            last = middle - 1;
            
        } 
        middle=(first+last)/2;      
    }

    if(first > key)
    {
        printf("Not in list\n");
    }
    return 0;

}