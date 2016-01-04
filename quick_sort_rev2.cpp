//
// Created by dell-iman on 1/4/2016.
//
#include <iostream>

using namespace std;

void pivot(int *arr, const int left, const int right) {

}

void quick_sort(const int left, const int right, int *arr) {
    if (left < right) {
        int pivot = arr[left];
        int i = left;
        int j = right;
        do {
            do i++; while (arr[i] < pivot);
            do j--; while (arr[j] > pivot);
            if (i < j) swap(arr[i], arr[j]);
        } while (i < j);
        swap(arr[left], arr[j]);
        quick_sort(left, j, arr);
        quick_sort(j + 1, right, arr);
    }
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
}

int main() {
    int arr[] = {2, 20, 5, 16, 17, 4, 7, 3, INT16_MAX};
    quick_sort(0, 8, arr);
    print_array(arr, 9);
    return 0;
}