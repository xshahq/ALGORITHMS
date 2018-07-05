#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const int maxn = 30;
struct Matrix
{
    double v[maxn][maxn];
    int n, m;
    Matrix() { memset(v, 0, sizeof(v));}
    Matrix operator +(const Matrix& B)
    {
        Matrix C; C.n = n; C.m = m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                C.v[i][j] = v[i][j] + B.v[i][j];
        return C;
    }
    Matrix operator -(const Matrix& B)
    {
        Matrix C; C.n = n; C.m = m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                C.v[i][j] = v[i][j] - B.v[i][j];
        return C;
    }
    Matrix operator *(const Matrix &B)
    {
        Matrix C; C.n = n; C.m = B.m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(v[i][j] == 0) continue;
                for(int k = 0; k < m; k++)
                    C.v[i][k] += v[i][j]*B.v[j][k];
            }
        return C;
    }
    void prepare()
    {
        int _n = 1;
        while(_n < n)
            _n <<= 1;
        while(_n < m)
            _n <<= 1;
        for(int i = 0; i < n; i++)
            for(int j = m; j < _n; j++)
                v[i][j] = 0;
        for(int i = n; i < _n; i++)
            for(int j = 0; j < _n; j++)
                v[i][j] = 0;
        n = m = _n;
    }
    void read()
    {
        cin>>n>>m;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin>>v[i][j];
    }
    Matrix get(int i1, int j1, int i2, int j2)
    {
        Matrix C; C.n = i2-i1+1; C.m = j2-j1+1;
        for(int i = i1-1; i < i2; i++)
            for(int j = j1-1; j < j2; j++)
                C.v[i-i1+1][j-j1+1] = v[i][j];
        return C;
    }
    void give(Matrix &B, int i1, int j1, int i2, int j2)
    {
        for(int i = i1-1; i < i2; i++)
            for(int j = j1-1; j < j2; j++)
                v[i][j] = B.v[i-i1+1][j-j1+1];
    }
    void print()
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout<<setw(6)<<v[i][j];
            cout<<endl;
        }

    }
}A, B;

Matrix Strassen(Matrix &X, Matrix &Y)
{
    if(X.n == 1) return X*Y;
    int n = X.n;
    Matrix A[2][2], B[2][2], S[10], P[7];
    A[0][0] = X.get(1, 1, n/2, n/2);
    A[0][1] = X.get(1, n/2+1, n/2, n);
    A[1][0] = X.get(n/2+1, 1, n, n/2);
    A[1][1] = X.get(n/2+1, n/2+1, n, n);
    B[0][0] = Y.get(1, 1, n/2, n/2);
    B[0][1] = Y.get(1, n/2+1, n/2, n);
    B[1][0] = Y.get(n/2+1, 1, n, n/2);
    B[1][1] = Y.get(n/2+1, n/2+1, n, n);
    S[0] = B[0][1] - B[1][1];
    S[1] = A[0][0] + A[0][1];
    S[2] = A[1][0] + A[1][1];
    S[3] = B[1][0] - B[0][0];
    S[4] = A[0][0] + A[1][1];
    S[5] = B[0][0] + B[1][1];
    S[6] = A[0][1] - A[1][1];
    S[7] = B[1][0] + B[1][1];
    S[8] = A[0][0] - A[1][0];
    S[9] = B[0][0] + B[0][1];
    P[0] = Strassen(A[0][0], S[0]);
    P[1] = Strassen(S[1], B[1][1]);
    P[2] = Strassen(S[2], B[0][0]);
    P[3] = Strassen(A[1][1], S[3]);
    P[4] = Strassen(S[4], S[5]);
    P[5] = Strassen(S[6], S[7]);
    P[6] = Strassen(S[8], S[9]);
    B[0][0] = P[4] + P[3] - P[1] + P[5];
    B[0][1] = P[0] + P[1];
    B[1][0] = P[2] + P[3];
    B[1][1] = P[4] + P[0] - P[2] - P[6];
    X.give(B[0][0], 1, 1, n/2, n/2);
    X.give(B[0][1], 1, n/2+1, n/2, n);
    X.give(B[1][0], n/2+1, 1, n, n/2);
    X.give(B[1][1], n/2+1, n/2+1, n, n);
    return X;
}
