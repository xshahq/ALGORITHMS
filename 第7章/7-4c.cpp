#include<bits/stdc++.h>
using namespace std;
int PARTITION(int* arr,int l,int r)
{
    int t = l;
    for(int i = l;i < r;++i)
        if(arr[i] < arr[r])
            swap(arr[i],arr[t++]);//用了stl的swap()函数
    swap(arr[t],arr[r]);
    return t;
}
void QUICK_SORT(int* arr,int l,int r)
{
    while(l < r)
    {
        int mid = (l + r) / 2;
        int nextpos = PARTITION(arr,l,r);
        if(nextpos < mid)
        {
            QUICK_SORT(arr,l,nextpos - 1);
            l = nextpos + 1;
        }
        else
        {
            QUICK_SORT(arr,nextpos + 1,r);
            r = nextpos - 1;
        }
    }
}