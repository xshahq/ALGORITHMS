#include<bits/stdc++.h>
using namespace std;
struct section
{
    int l,r;
    int operator==(section s1)
    {
        if(l <= s1.l && s1.l <= r)
            return 1;
        return 0;
    }
    int operator<(section s1)
    {
        if(l < s1.l && r < s1.r)
            return 1;
        return 0;
    }
    friend ostream& operator<<(ostream& os,section s1);
};
ostream& operator<<(ostream& os,section s1)
{
    return cout << "[" << s1.l << "," << s1.r << "]";
}
pair<int,int> PARTITION(section* arr,int l,int r)
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
void QUICK_SORT(section* arr,int l,int r)
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
//测试数据
int main()
{
    section s1,s2,s3,s4,s5,s6;
    s1.l = 7;
    s1.r = 9;
    s2.l = 2;
    s2.r = 4;
    s3.l = 3;
    s3.r = 6;
    s4.l = 7;
    s4.r = 8;
    s5.l = 5;
    s5.r = 7;
    s6.l = 0;
    s6.r = 1;
    section arr[6] = {s1,s2,s3,s4,s5,s6};
    QUICK_SORT(arr,0,5);
    for(int i = 0;i < 6;++i)
        cout << arr[i];
    return 0;
}
