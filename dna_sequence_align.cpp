#include <iostream>
#define IN_DEL 2 //Insertion or deleting
#define MUT 1    //Mutation cost
using namespace std;

int seq_align(int i, int j, int arr1[], int arr2[], int size1, int size2){
    if(i == size1 )
        return 2 * (size2 - j);
    else if(j == size2 )
        return 2 * (size1 - i);
    else
    {
        int first;
        if(arr1[i] == arr2[j])
            first = 0 + seq_align(i + 1, j + 1, arr1, arr2, size1, size2);
        else
            first = 1 + seq_align(i + 1, j + 1, arr1, arr2, size1, size2);
        int second = IN_DEL + seq_align(i, j + 1, arr1, arr2, size1, size2);
        int third = IN_DEL + seq_align(i + 1, j, arr1, arr2, size1, size2);

        int min = first;
        if(second < min)
            min = second;
        if(third < min)
            min = third;

        return min;
    }

}

int main(){
    int arr1[] = {1,2,3,2};
    int arr2[] = {3,2,4,2};

    cout<<seq_align(0 , 0, arr1, arr2, 4, 4);

    return 0;
}
