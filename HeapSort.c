#include<stdio.h>
#include<stdlib.h>

void swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}

void heapify(int arr[] , int n , int p)
{
    int gt=p;
    int lc = 2*p+1;
    int rc = 2*p+2;
    if(lc<n && arr[lc]>arr[gt])
        gt=lc;
    if(rc<n && arr[rc]>arr[gt])
        gt=rc;
    if(gt!=p)
    {
        swap(&arr[p],&arr[gt]);
        heapify(arr,n,gt);
    }
}
void heap_sort(int arr[] , int n) /// TIME COMPLEXITY 1.BEST CASE : NLOGN 2. WORST CASE : NLOGN
{
    int i;
    for(i=(n+1)/2;i>=0;i--)  /// BUILDING MAX HEAP
    {
        heapify(arr,n,i);
    }
    int cs=n;
    while(cs>1)  /// REMOVING ELEMENTS FROM TOP AND MOVING IT AT LAST
    {
        swap(&arr[0],&arr[cs-1]);
        cs--;
        heapify(arr,cs,0); /// AGAIN CALLING HEAPIFY TO BUILD MAX HEAP
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

    heap_sort(arr,n); /// HEAP SORT

    printf("\nSORTED ARRAY IS \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
