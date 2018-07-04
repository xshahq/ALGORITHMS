#include<bits/stdc++.h>
using namespace std;
int FIND_MAX_SUBARRAY(int* arr,int length)
{
    int ans = INT_MIN;
    for(int i = 0;i < length;++i)
    {
        int sum = 0;
        for(int j = i;j < length;++j)
        {
            sum += arr[j];
            ans = max(sum,ans);
        }
    }
    return ans;
}