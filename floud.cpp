#include <iostream>

using namespace std;

int floyd(int n, int **d) {

    for(int i = 0; i < n ; i++) {
        for(int j = 0; j < n ; j++) {
            for(int k = 0; k < n; k++) {
                if(d[i][k] + d[k][j] < d[i][j]){
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
}

int main() {
    return 0;
}
