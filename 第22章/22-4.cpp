#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<list>
using namespace std;
#define WHITE 0
#define BLACK 1
#define GREY 2
#define N 100
list<int> arr[N];
int color[N],nodeNum,edge,time = 0,m[N],l[N];
int DFStravel(int);
void input()
{
    cin >> nodeNum >> edge;
    for(int i = 0;i < nodeNum;++i)
        cin >> l[i];
    for(int i = 0;i < edge;++i)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        arr[temp1].push_back(temp2);
    }
}
void output()
{
    for(int i = 0;i < nodeNum;++i)
    {
        for(auto pos = arr[i].begin();pos != arr[i].end();++pos)
            cout << *pos;
        cout << endl;
    }
}
int DFStravel(int num)
{
    color[num] = GREY;
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            m[num] = min(m[num],DFStravel(temp));
        else
            m[num] = m[temp];
    }
    color[num] = BLACK;
    return m[num];
}
int minReachable()
{
    for(int i = 0;i < nodeNum;++i)
    {
        color[i] = WHITE;
        m[i] = l[i];
    }
    for(int i = 0;i < nodeNum;++i)
        if(color[i] == WHITE)
            m[i] = min(m[i],DFStravel(i));
}
int main()
{
    input();
    minReachable();
    for(int i = 0;i < nodeNum;++i)
        cout << m[i] << endl;
    return 0;
}
