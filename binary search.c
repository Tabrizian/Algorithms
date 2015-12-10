#include <stdio.h>
int bsearch(int start ,int end,int arr[],int value)
{
    int mid=(start+end)/2;
    if(value==arr[mid])
        return 1;
    else if(start>=end)
        return -1;
    else{
        if(value>arr[mid])
            return bsearch(mid+1,end,arr,value);
        else
            return bsearch(start,mid-1,arr,value);
    }

}
