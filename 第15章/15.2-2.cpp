#include<bits/stdc++.h>
using namespace std;
#define N  6    
void MATRIX_CHAIN_MULTIPLY(int p[N+1], int m[N + 1][N + 1],int s[N+1][N+1])
        {
            int j = i + l - 1;
            m[i][j] = 999999999;
            for (int k = i; k < j; k++)
			{
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
				{
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
//打印括号化的矩阵链
void print(int s[N + 1][N + 1],int i,int j)
{
    if (i == j) cout << "A" << i;
    else{
        cout << "(";
        print(s, i, s[i][j]);
        print(s, s[i][j]+1, j);
        cout << ")";
    }
}