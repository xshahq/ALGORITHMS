#include<bits/stdc++.h>
using namespace std;
int c,value[100];//c为付出的固定成本，value为每段钢管的价值
int dp[100];
int cut(int length)
{
    for(int i = 1;i <= length;++i)
        dp[i] = value[i];
    for(int i = 1;i <= length;++i)
        for(int j = 1;j <= i;++j)
        {
            dp[i] = max(dp[i],dp[i - j] + dp[j] - c);
        }
        return dp[length];
}