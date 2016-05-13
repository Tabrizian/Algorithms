#include <iostream>
using namespace std;

int n;
int **w;
int *x;
int k;

void get_input(int n, int **w) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
}

bool promising(int i, int j) {
    if(w[i][j] == 1 && x[i] == j)
        return false;
    return true;
}

void graph_coloring(int i) {
    if(i == n) {
        for(int i = 0; i < n; i++)
            cout << x[i] << " ";
    } else {
        for(int j = 0; j < k; j++) {
            if(promising(i, j)) {
                x[i] = j;
                graph_coloring(i + 1);
            }
        }
    }
}

int main() {

    int n;

    cin >> n;

    int **w = new int*[n];
    for(int i = 0; i < n; i++) {
        w[i] = new int[n];
    }

    x = new int[n];

    get_input(n, w);

    cin >> k;

    graph_coloring(0);

    return 0;
}
