const int MOD = 1e4;
class Matrix
{
public:
    int N; // 矩阵维数
    int** m; // 存储矩阵的二维数组
    Matrix(int n = 2) {
        N = n;
        m = new int*[n];
        for (int i=0; i < n; ++i) m[i] = new int[n];
        clear();
    }

// 将矩阵清空为零矩阵
    void clear() {
        for (int i=0; i < N; ++i)
            memset(m[i], 0, sizeof(int) * N);
    }

// 将矩阵设定为单位矩阵
    void unit() {
        clear();
        for (int i=0; i < N; ++i) m[i][i] = 1;
    }

// 矩阵的赋值
    Matrix operator= (const Matrix &othr) {
        Matrix(othr.N);
        for(int i=0; i < othr.N; ++i)
            for(int j=0; j < othr.N; ++j)
                m[i][j] = othr.m[i][j];
        return *this;
    }

// 矩阵的乘法
//!假设所有因子均为同阶方阵
    Matrix operator* (Matrix &othr) {
        Matrix ret(othr.N);
        for (int i=0; i < othr.N; ++i)
            for (int j=0; j < othr.N; ++j)
                for (int k=0; k < othr.N; ++k)
                    (ret.m[i][j] += m[i][k] * othr.m[k][j]) %= MOD;
        return ret;
    }
};

Matrix qMPow(Matrix &A, int n) {
    Matrix rslt(A.N);
    rslt.unit();
    if (n == 0) return rslt;
    while (n) {
        if (n & 1) rslt = rslt * A;
        A = A * A;
        n >>= 1;
    }
    return rslt;
}
