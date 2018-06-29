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
void QUICK_SORT(int* arr,int l,int r)
{
    if(l < r)
    {
        pair<int,int> nextpos = PARTITION(arr,l,r);
        int q = nextpos.first;
        int t = nextpos.second;
        QUICK_SORT(arr,l,q - 1);
        QUICK_SORT(arr,t + 1,r);

    }
}