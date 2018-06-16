#include<bits/stdc++.h>
using namespace std;
int value[100];
int dp[100],LEFT[100] = {0},RIGHT[100];//left和right分别记录切割的两段的长度
int MEMOIZED_CUT_ROD(int length)
{
    for(int i = 1;i <= length;++i)
    {
        dp[i] = value[i];
        RIGHT[i] = value[i];
    }
    for(int i = 1;i <= length;++i)
        for(int j = 1;j <= i;++j)
            if(dp[i] < (dp[i - j] + dp[j]))
            {
                dp[i] = dp[i - j] + dp[j];
                RIGHT[i] = i - j;
                LEFT[i] = j;
            }
    return dp[length];
}