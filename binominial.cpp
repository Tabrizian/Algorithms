#include <iostream>

using namespace std;

int binom(int m, int n) {

    int bi[m+1][n+1];

    bi[0][0] = 0;
    bi[1][0] = 1;
    bi[0][1] = 1;
    for(int i = 1;i <= n; i++) {
        for(int j = 1;j <= n; j++) {
            bi[i][j] = bi[i-1][j] + bi[i-1][j-1];
        }
    }

    return bi[m][n];
}

int main() {

    cout << binom(3, 2) << endl;
    return 0;
}
