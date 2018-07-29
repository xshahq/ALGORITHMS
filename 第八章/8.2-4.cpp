#include<bits/stdc++.h>
using namespace std;
int co[1000];
void counting(int* arr,int length,int k)//k表示输入的数的最大值
{
    for(int i = 0;i < length;++i)
        co[arr[i]] += 1;
    for(int i = 0;i <= k;++i)
        co[i] += co[i - 1];
}
int query(int a,int b)
{
    if(!a)
        return co[b];
    return co[b] - co[a - 1];
}