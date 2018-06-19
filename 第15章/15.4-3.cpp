#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000] = {0};
string str1,str2;//两个用来比较的字符串
int LCS()
{
    int ans = 0;
    for(int i = str1.length() - 1;i >= 0;--i)
        for(int j = str2.length() - 1;j >= 0;--j)
        {
            if(str1[i] == str2[j])
                dp[i][j]= max(dp[i][j],dp[i + 1][j] + 1);
            else
                dp[i][j] = max(dp[i][j + 1],dp[i + 1][j]);
            ans = max(ans,dp[i][j]);
        }
    return ans;
}