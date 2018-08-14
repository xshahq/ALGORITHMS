#include<bits/stdc++.h>
using namespace std;
void exchange(int* arr,int n)
{
    for(int i = 0;i < n;++i)
    {
        int min1 = arr[i],count1 = i;
        for(int j = i;j < n;++j)
            if(arr[j] < min1)
            {
                count1 = j;
                min1 = arr[j];
            }
        int temp = arr[count1];
        arr[count1] = arr[i];
        arr[i] = temp;
    }
}
//测试数据
int main()
{
    int arr[10] = {3,4,2,5,1,1,4,9,8,7};
    for(int i = 0;i < 10;++i)
        cout << arr[i] << endl;
}