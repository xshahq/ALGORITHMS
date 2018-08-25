#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
#define N 21
struct hashtable
{
    pair<int,int> arr[N];
    hashtable()
    {
        for(int i = 0;i < N;++i)
            arr[i].second = -1;
    }
    int HASH1(int key);
    int HASH2(int key);
    int SEARCH(int key);
    void DELETE(int key);
    void INSERT(int key);
};
int hashtable::HASH1(int key)
{
    return key % N;
}
int hashtable::HASH2(int key)
{
    return 1 + (key % N - 1);
}
int hashtable::SEARCH(int key)
{
    int i = 0,count1 = 0;
    int index = (HASH1(key) + i * HASH2(key)) % N;
    while(i < N && arr[index].second != -1)
    {
        if(arr[index].second && arr[index].first == key)
        {
            count1 = 1;
            break;
        }
        ++i;
        index = (HASH1(key) + i * HASH2(key)) % N;
    }
    if(count1)
        return index;
    return -1;
}
void hashtable::INSERT(int key)
{
    int i = 0;
    int index = (HASH1(key) + i * HASH2(key)) % N;
    while(i < N && arr[index].second != -1 && arr[index].second)
    {
        ++i;
        index = (HASH1(key) + i * HASH2(key)) % N;
    }
    if(i < N)
    {
        arr[index].first = key;
        arr[index].second = 1;
    }
    else
        cout << "it's full" << endl;
}
void hashtable::DELETE(int key)
{
    int i = SEARCH(key);
    if(i == -1)
    {
        cout << "not exist this key" << endl;
        return;
    }
    arr[i].second = 0;
}
//测试数据
int main()
{
    hashtable ht;
    for(int i = 0;i < N;++i)
    {
        ht.INSERT(i);
    }
    for(int i = 0;i < N;++i)
        cout << ht.SEARCH(i) << endl;
    for(int i = 0;i < 10;++i)
        ht.DELETE(i);
    for(int i = 0;i < N;++i)
        cout << ht.SEARCH(i) << endl;
    for(int i = 0;i < N;++i)
        ht.INSERT(i);
    return 0;
}