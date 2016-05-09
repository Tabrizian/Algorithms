#include <iostream>
#include <cmath>

using namespace std;

int n;
int *x;

// k is the row of queen for the i-th queen
bool promising(int i, int k) {
    for(int j = 0; j < i; j++) {
        if(k == x[j] || i == j || abs(x[j] - k) == abs(j - i)) {
            return false;
        }
    }

    return true;
}

void n_queen(int i) {
    if(i == n) {
        for(int j = 0; j < n; j++) {
            cout << x[j] << " ";
        }
        cout << endl;
    } else {
        for(int j = 0; j < n; j++) {
            if(promising(i, j)) {
                x[i] = j;
                n_queen(i + 1);
            }
        }
    }
}


int main() {

    cin >> n;

    x = new int[n];

    n_queen(0);
    return 0;
}
