const int N1 = 55, N2 = 55;
struct Match {
    VI head[N1];
    int mat[N2];
    bool used[N2];

    void init(int n1) {REP(i, n1) head[i].clear();}
    void add(int x, int y) {head[x].pb(y);}
    bool find_path(int x) {
        for(int y: head[x]) {
            if(used[y]) continue;
            used[y] = true;
            if(mat[y] == -1 || find_path(mat[y])) {
                mat[y] = x;
                return true;
            }
        }
        return false;
    }

    int match(int n1) {
        memset(mat, -1, sizeof(mat));
        int ret = 0;
        REP(i, n1) {
            memset(used, 0, sizeof(used));
            if(find_path(i)) ++ret;
        }
        return ret;
    }
}match;

