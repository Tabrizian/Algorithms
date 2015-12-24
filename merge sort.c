#include <stdio.h>
#include <stdlib.h>

void arr_cpy(int dst[],int src[],int start,int end)
{
    int i=0;
    for(;i+start<end;i++)
    {
        dst[i]=src[i+start];
    }
}
void arr_cpy2(int dst[],int src[],int start1,int num1,int start2)
{
    int i=0;
    for(;i<num1;i++)
    {
        dst[i+start1]=src[i+start2];
    }
}
void merge(int arr1[],int mid,int arr2[],int n1,int arr[])
{
    int i=0,j=0,k=0;
    while(i<mid&&j<n1)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            j++;
        }
        k++;
    }
    if(i>=mid)
    {
        arr_cpy2(arr,arr2,k,n1,j);
    }
    if(j>=n1)
    {
        arr_cpy2(arr,arr1,k,mid,i);
    }
}
void merge_sort(int arr[],int n)
{
    int mid=n/2;
    int n1=n-mid;
    int * arr1;
    int * arr2;
    arr1=(int *)malloc(mid*sizeof(int));
    if(arr1==NULL)
    {
        printf("Cannot allocate memory!!\n");
        exit(0);
    }
    arr2=(int *)malloc(n1*sizeof(int));
    if(arr2==NULL)
    {
        printf("Cannot allocate memory!!\n");
        exit(0);
    }
    if(n>1)
    {
        arr_cpy(arr1,arr,0,mid);
        arr_cpy(arr2,arr,mid,n);
        merge_sort(arr1,mid);
        merge_sort(arr2,n1);
        merge(arr1,mid,arr2,n1,arr);
    }
}
int main()
{
    int a[]={'v','e','u','p','F','f','b','A','a'};
    int i;
    merge_sort(a,sizeof(a)/sizeof(int));
    for(i=0;i<sizeof(a)/sizeof(int);i++)
    {
        printf("%c ",a[i]);
    }
    return 0;
}
