#include<stdio.h>
#include<stdlib.h>

void swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertion_sort(int arr[],int n) // TIME COMPLEXITY 1.BEST CASE : N 2. WORST CASE : N^2
{
    int i,j;
    for(i=1;i<n;i++)
    {
        int temp = arr[i];
        for(j=i-1;j>=0;j--)
        {
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else
                break;
        }
        arr[j+1]=temp;

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
    insertion_sort(arr,n);
    printf("\nSORTED ARRAY IS \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
