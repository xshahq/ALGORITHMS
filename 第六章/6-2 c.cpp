#include<bits/stdc++.h>
using namespace std;
int d;//d叉堆
void MAX_HEAP(int* arr,int i,int length)
{
    int l = i * d + 1,dis = d;
    if(l > length)
    {
        dis = d - (l - length);
        if(dis < 0)
            dis = 0;
        l = length;
    }
    int max1 = i;
    while(dis)
    {
        max1 = arr[max1 - 1] > arr[l - 1] ? max1 : l;
        --l;
        --dis;
    }
    if(max1 != i)
    {
        swap(arr[i - 1],arr[max1 - 1]);
        MAX_HEAP(arr,max1,length);
    }
}
int EXTRACT_MAX(int* arr,int length)
{
    int temp = arr[0];
    arr[0] = INT_MIN;
    MAX_HEAP(arr,1,length);
    return temp;
}