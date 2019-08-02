#include<stdio.h>
#include<stdlib.h>
void swap(int *a , int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}
void merge(int arr[] , int l, int m ,int h) // TIME COMPLEXITY 1.BEST CASE : NLOGN 2. WORST CASE : NLOGN
{

    int i=l;
    int j=m+1;
    int *b = (int*)malloc(sizeof(int)*(h-l+1));
    int k=0;
    while(i<=m && j<=h)
    {
        if(arr[i]<arr[j])
        {
            b[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    if(i<=m)
    {
        while(i<=m)
        {
            b[k]=arr[i];
            i++;
            k++;
        }
    }
    if(j<=h)
    {
        while(j<=h)
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    for(i=0;i<k;i++)
    {
        arr[l]=b[i];
        l++;
    }

}
void merge_sort(int arr[],int l,int h) // TIME COMPLEXITY 1.BEST CASE : NLOGN 2. WORST CASE : NLOGN
{
    if(l<h)
    {
        int m = (l+h)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,h);
        merge(arr,l,m,h);
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
    merge_sort(arr,0,n-1);
    printf("\nSORTED ARRAY IS \n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
