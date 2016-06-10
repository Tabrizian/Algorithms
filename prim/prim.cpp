void prim(int **w, int n, set F) {
    int distance[n];
    int nearest[n];
    bool is_black[n];

    is_black[0] = true;

    // init
    for(int i = 1; i < n; i++) {
        distance[i] = w[i][0];
        is_black[i] = false;
        nearest[i] = 0;
    }

    while ( sizeof(F) < n) {
        int vnear;
        int tmp_min = INF;

        // select
        for(int i = 0; i < n; i++) {
            if(!is_black[i]) {
                if(distance[i] < tmp_min) {
                    tmp_min = distance[i];
                    vnear = i;
                }
            }
        }

        is_black[vnear] = true;
        F = F + ({(vnear, nearest[vnear])});

        // update
        for(int i = 0; i < n; i++) {
            if(!is_black[i]) {
                if(w[vnear][i] < distance[i]) {
                    distance[i] = w[vnear][i];
                    nearest[i] = vnear;
                }
            }
        }


    }
}
