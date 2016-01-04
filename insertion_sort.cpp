//
// Created by dell-iman on 1/4/2016.
//
#include <iostream>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insert(int *arr, int index) {
    int i = index - 1;
    int element = arr[index];
    while (arr[i] > element && i >= 0) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = element;
}

void print_array(int *arr, int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << ", ";
    }
    cout << "]" << endl;
}

void sort_array(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        insert(arr, i);
    }
}

int main() {
    int arr[] = {4, 3, 2, 1};
    sort_array(arr, 4);
    print_array(arr, 4);
    return 0;
}