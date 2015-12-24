//
// Created by dell-iman on 12/24/2015.
//


//
// Created by dell-iman on 12/19/2015.
//

#include <iostream>

#define MAX_SIZE 100
using namespace std;

class max_heap {
    int elements[MAX_SIZE];
    int last = 0;
public:
    void insert(int data);

    bool is_empty();

    int delete_max();

private:
    void heapify(int root);
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void max_heap::insert(int data) {
    if (last == MAX_SIZE) return;
    if (last == 0) {
        elements[0] = data;
        last++;
    }
    else {
        bool added = false;
        int i = last;
        last++;
        elements[i] = data;
        while (!added) {
            if (elements[(i - 1) / 2] >= data) {
                added = true;
            } else {
                swap(&elements[i], &elements[(i - 1) / 2]);
                i = i / 2;
            }
        }
    }
}

int max_heap::delete_max() {
    int ans = elements[0];
    swap(elements[--last], elements[0]);
    int i = 0;
    if (((2 * i + 2) < last && elements[i] > elements[2 * i + 1] && elements[i] > elements[2 * i + 2]) ||
        (2 * i + 2 == last && elements[i] > elements[2 * i + 1])) {
        return ans;
    } else if (2 * i >= last) {
        return ans;
    } else {
        heapify(0);
        return ans;
    }
}

void max_heap::heapify(int root) {
    if (((2 * root + 2) < last && elements[root] > elements[2 * root + 1] && elements[root] > elements[2 * root + 2]) ||
        (2 * root + 2 == last && elements[root] > elements[2 * root + 1])) {
        return;
    } else if (2 * root + 1 >= last) {
        return;
    } else if (2 * root + 2 == last) {
        swap(&elements[root], &elements[2 * root + 1]);
        heapify(2 * root + 1);
    } else {
        if (elements[2 * root + 1] > elements[2 * root + 2]) {
            swap(&elements[root], &elements[2 * root + 1]);
            heapify(2 * root + 1);
        } else {
            swap(&elements[root], &elements[2 * root + 2]);
            heapify(2 * root + 2);
        }
    }
}

bool max_heap::is_empty() {
    return last == 0;
}

int main() {
    max_heap heap;
    heap.insert(20);
    heap.insert(18);
    heap.insert(22);
    heap.insert(13);
    heap.insert(15);
    heap.insert(10);
    heap.insert(9);
    heap.insert(26);
    for (int i = 0; !heap.is_empty(); ++i) {
        cout << heap.delete_max() << " ";
    }
    return 0;
}


