bool promising(Solution s, int k) {
    if(s.w + k*w[s.i] > W) {
        return false;
    } else {
        int tmpW = s.w;
        int tmpP = s.p;

        for(int i = s.i + 1; i < n; i++) {
            if(w[i] + tmpW <= W) {
                tmpW += w[i];
                tmpP += p[i];
            } else {
                tmpW = W;
                tmpP = (p[i])/(w[i])*(W-w[i]);
            }
        }

        if(tmpP > bsf.p)
            return true;
        else
            return false;
    }
}
void knapsack_bb_dfs(Solution s) {
    if(s.i == n) {
        if(s.p > bsf.p)
            bfs = s;
    } else {
        for(int i = 0; i < 1; i++) {
            if(promising(s, k)) {
                s.w += k*w[s.i];
                s.p += k*p[s.i];
                s.x[s.i] = k;
                s.i++;
                knapsack_bb_dfs(s);
            }
        }
    }
}
