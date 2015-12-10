#include <iostream>
using namespace std;
#define SIZE 5
struct sum{
    int start;
    int end;
    int val;
};
int max(int a,int b){
    if(a > b)
        return a;
    else
        return b;
}
int max(int *arr,int size){
    int max_num = arr[0];
    for(int i = 1; i < size;i++)
         max_num = max(max_num,arr[i]);
    return max_num;
}
int max_calc(struct sum values[],int size){
    int max_num = 0;
    for(int i = 1; i < size;i++)
    {
        if(values[i].val > values[max_num].val)
            max_num = i;
    }
    return max_num;
}
int main(){
    struct sum sums[SIZE];
    int arr[] = {1, 2, -1, -4, -20};
    int start = -1,end = -1;
    for(int i=0;i<SIZE;i++)
        sums[0].val = 0;
    if(arr[0] > 0){
        sums[0].val = arr[0];
        sums[0].start = 0;
        sums[0].end = 0;
    }

    for(int i = 1 ;i < SIZE;i++)
    {
        sums[i].val = max(sums[i-1].val + arr[i],arr[i]);
        if(sums[i].val == arr[i]){
            sums[i].start = i;
            sums[i].end = i;
        } else {
            sums[i].start = sums[i - 1].start;
            sums[i].end = i;
        }
    }
    for(int i = 0;i<SIZE;i++){
        cout<<i<<" :";
        cout<<sums[i].val<<" "<<sums[i].start<<" "<<sums[i].end<<endl;
    }

    return 0;
}
