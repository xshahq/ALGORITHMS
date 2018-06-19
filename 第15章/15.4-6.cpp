#include<bits/stdc++.h>
using namespace std;
int dp[10000] = {0};
string str;
int LIS()
{
    vector<int> v;
    for(int i = str.length() - 1;i >= 0;--i)
    {
        if(i == str.length() - 1)
            v.push_back(str[i]);
        else
        {
            if(str[i] < v[v.size() - 1])
                v.push_back(str[i]);
            else
            {
                vector<int>::iterator pos = upper_bound(v.begin(),v.end(),str[i]);
                *pos = str[i];
            }
        }
    }
    return v.size();
}