#include<bits/stdc++.h>
using namespace std;
int dp[10000] = {0};
string str;
int LIS()
{
    int ans = 0;
    for(int i = str.length() - 1;i >= 0;--i)
    {
        if(i == str.length() - 1)
            dp[i] = 1;
        else
            for(int j = i;j < str.length();++j)
                if(str[j] > str[i])
                    dp[i] = max(dp[i],dp[j] + 1);
        ans = max(ans,dp[i]);
    }
    return ans;
}