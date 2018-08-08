#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
using namespace std;
#define N 1000
struct assit
{
    pair<int,int> arr1[N];
    int length = 0;

};
struct addtable
{
    int arr[N];
    assit a;
    void init()
    {
        a.length = 0;
    }
    void INSERT(int ele,int key)
    {
        arr[key] = a.length;
        pair<int,int> p(key,ele);
        a.arr1[a.length++] = p;
    }
    void DELETE(int key)
    {
        a.arr1[arr[key]] = a.arr1[a.length - 1];
        int temp = a.arr1[a.length - 1].second,temp1 = a.arr1[a.length - 1].first;
        arr[temp1] = arr[key];
        pair<int,int> p(temp1,temp);
        a.arr1[arr[key]] = p;
        a.length--;
    }
    int SEARCH(int key)
    {
        if(arr[key] >= a.length || a.arr1[arr[key]].first != key)
            return -1;
        return a.arr1[arr[key]].second;
    }
};
//测试数据
int main()
{
    addtable at1;
    at1.INSERT(1,0);
    at1.INSERT(2,1);
    at1.INSERT(3,2);
    cout << at1.SEARCH(2);
    at1.DELETE(1);
    cout << at1.SEARCH(2) << at1.SEARCH(1);
    return 0;
}