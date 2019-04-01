#include<stdio.h>
#include<stdlib.h>

void swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void selection_sort(int arr[], int n) // TIME COMPLEXITY 1.BEST CASE : N^2 2. WORST CASE : N^2
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        int min =i;
        for(j=min+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(&arr[i],&arr[min]);
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
    selection_sort(arr,n);
    printf("\nSORTED ARRAY IS \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
