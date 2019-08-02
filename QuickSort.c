#include<stdio.h>
#include<stdlib.h>

void swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}

int partition(int arr[] , int l , int h)
{
    int low = l;
    int up = h;
    int pivot = arr[low];  /// CONSIDERING FIRST ELEMENT AS PIVOT
    while(low<up)
    {
        while(arr[low]<=pivot && low<h) /// ELEMENT LESS THAN PIVOT SKIPPED
        {
            low++;
        }
        while(arr[up]>pivot)  /// ELEMENT GREATER THAN PIVOT ARE SKIPPED
        {
            up--;
        }
        if(low<up)
        {
            swap(&arr[low],&arr[up]);  /// TWO ELEMENT PLACED AT THEIR PLACE
        }
    }
    swap(&arr[up],&arr[l]);
    return up;
}

void quick_sort(int arr[] , int l , int h) /// TIME COMPLEXITY 1.BEST CASE : NLOGN 2. WORST CASE : N^2
{
    if(l<h)
    {
        int position = partition(arr,l,h); ///PARTIONING THE ARRAY
        quick_sort(arr,l,position);  /// FOR LOWER HALF
        quick_sort(arr,position+1,h); /// FOR UPPER HALF
    }
}

int main()
{
    int i,n;

    printf("Enter the number of elements\n");
    scanf("%d",&n);

    printf("Enter the elements:\n");

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

    quick_sort(arr,0,n-1); /// QUICK SORT

    printf("\nSORTED ARRAY IS \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
