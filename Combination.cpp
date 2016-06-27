const int MOD = 1e9 + 7;
const int N = 2e5 + 10; // n <= 1e5, mod 为素数
struct Combination{
    int g[N], f[N];
    Combination() {
        g[0] = f[0] = 1;
        FOR(i, 1, N - 1) {
            g[i] = (LL)g[i-1] * i % MOD;
            f[i] = pow(g[i], MOD - 2);
        }
    }
    int pow(int a, int b) {
        LL ret=1,tmp=a;
        while(b) {
            if (b & 1) ret=(ret*tmp) % MOD;
            tmp=(tmp*tmp) % MOD;
            b >>= 1;
        }
        return ret % MOD;
    }
    int c(int n,int k) {
        LL ret = g[n];
        ret = (ret * f[k]) % MOD;
        ret = (ret * f[n-k]) % MOD;
        return ret;
    }
}cob;


