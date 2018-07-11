#include<bits/stdc++.h>
using namespace std;
int arrmin[100],pos[100];
int arr[100][100];
void calu(int m,int n,int beg,int mult)
{
    if(m == 1)
    {
        int min1 = INT_MAX;
        for(int i = 0;i < n;++i)
            if(min1 > arr[beg - 1][i])
            {
                min1 = arr[beg - 1][i];
                pos[beg - 1] = i;
            }
        arrmin[beg - 1] = min1;
        return;
    }
    calu(m / 2,n,beg * 2,mult * 2);
    int i = beg - 1;
    while(i < m)
    {
        int left = i == beg - 1 ? 0 : pos[i - mult];
        int right = i == m - 1 ? n - 1 : pos[i + mult];
        int min1 = INT_MAX;
        for(int j = left;j <= right;++j)
            if(min1 > arr[i][j])
            {
                min1 = arr[i][j];
                pos[i] = j;
            }
        arrmin[i] = min1;
        i += mult * 2;
    }
}