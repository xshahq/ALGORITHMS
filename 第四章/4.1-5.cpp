#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int FIND_MAX_SUBARRAY(int* arr,int length)
{
    int ans = INT_MIN,sum = 0;
    for(int i = 0;i < length;++i)
    {
        sum += arr[i];
        ans = max(ans,sum);
        if(sum < 0)
            sum = 0;
    }
    return ans;
}