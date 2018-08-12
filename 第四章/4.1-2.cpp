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
//测试数据
int main()
{
    int arr[16] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    cout << FIND_MAX_SUBARRAY(arr,16);
    return 0;
}
