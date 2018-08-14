#include<bits/stdc++.h>
using namespace std;
void insersort(int* arr,int length)
{
    for(int i = 1;i < length;++i)
    {
        int j = i - 1,temp = arr[i];
        while(j >= 0 && temp > arr[j])
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = temp;
    }
}
//测试数据
int main()
{
    int arr[10] = {3,7,6,9,8,4,2,10,1,9};
    insersort(arr,10);
    for(int i = 0;i < 10;++i)
        cout << arr[i] << endl;
}
