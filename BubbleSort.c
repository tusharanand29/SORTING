#include<stdio.h>
#include<stdlib.h>

void swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void bubble_sort(int arr[], int n) // TIME COMPLEXITY 1.BEST CASE : N^2 2. WORST CASE : N^2
{
    int i, j;
    for(i=0;i<n-1;i++)
    {
        int flag=0;
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag=1;
                swap(&arr[j],&arr[j+1]);
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

int main()
{
    int i,n;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    int *arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("YOUR ENTERED ARRAY IS\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    bubble_sort(arr,n);
    printf("\nSORTED ARRAY IS \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
