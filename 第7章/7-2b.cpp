#include<bits/stdc++.h>
using namespace std;
pair<int,int> PARTITION(int* arr,int l,int r)
{
    int t = l;
    for(int i = l;i < r;++i)
        if(arr[i] < arr[r])
            swap(arr[i],arr[t++]);//用了stl的swap()函数
    int temp = t;
    swap(arr[t],arr[r]);
    t++;
    for(int i = t + 1;i <= r;++i)
        if(arr[i] == arr[temp])
            swap(arr[i],arr[t++]);
    pair<int,int> p(temp,t - 1);
    return p;
}
//测试数据
int main()
{
    int arr[10] = {1,4,3,9,1,1,4,1,2,1};
    pair<int,int> p = PARTITION(arr,0,9);
    cout << p.first << p.second;
    return 0;
}