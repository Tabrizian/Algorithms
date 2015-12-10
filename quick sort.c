#include<stdio.h>
int good=1;
void swap(int * a1,int * a2)
{
    int temp;
    temp=*a1;
    *a1=*a2;
    *a2=temp;
}
void partion(int * arr,int start , int end,int * pivotpoint)
{
    int i,j;
    int pivotitem=arr[start];
    j=start;
    for(i=start+1;i<end;i++)
    {
        if(arr[i]<pivotitem)
        {
            j++;
            swap(&arr[i],&arr[j]);
        }
    }
    *pivotpoint=j;
    swap(&arr[start],&arr[*pivotpoint]);
}
void quick_sort(int * arr,int start ,int end)
{
    int pivotpoint=0;
    if(start<end)
    {
        partion(arr,start,end,&pivotpoint);
        int i=0;
        quick_sort(arr,start,pivotpoint-1);
        quick_sort(arr,pivotpoint+1,end);
    }
}
int main()
{
    int a[10000];
    int i;
    for(i=0;i<10000;i++)
        a[i]=rand()%20000;
    quick_sort(a,0,sizeof(a)/sizeof(int));
    for(i=0;i<sizeof(a)/sizeof(int);i++)
        printf("%5d ",a[i]);
    return 0;
}
