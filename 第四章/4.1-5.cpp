#include<bits/stdc++.h>
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
//测试数据
int main()
{
    int arr[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    cout << FIND_MAX_SUBARRAY(arr,16);
    return 0;
}
