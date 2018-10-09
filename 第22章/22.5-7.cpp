#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
#define WHITE 0
#define BLACK 1
#define GREY 2
#define N 100
list<int> arr[N];
list<int> tparr[N];
list<int> scc[N];
int color[N],nodeNum,edge,time = 0,d[N],f[N],type[N];
void DFStravel(int);
void input()
{
    cin >> nodeNum >> edge;
    for(int i = 0;i < edge;++i)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        arr[temp1].push_back(temp2);
    }
}
void DFS()
{
    for(int i = 0;i < nodeNum;++i)
        color[i] = WHITE;
    for(int i = 0;i < nodeNum;++i)
        if(color[i] == WHITE)
            DFStravel(i);
}
void DFStravel(int num)
{
    d[num] = time++;
    color[num] = GREY;
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            DFStravel(temp);
    }
    color[num] = BLACK;
    f[num] = time++;
}
int DFStravel2(int num)
{
    d[num] = time++;
    color[num] = GREY;
    int ret = 1;
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            ret = max(1 + DFStravel2(temp),ret);
    }
    color[num] = BLACK;
    f[num] = time++;
    return ret;
}
void DFStravel1(int num,int count1)
{
    color[num] = GREY;
    type[num] = count1;
    for(auto pos = tparr[num].begin();pos != tparr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            DFStravel1(temp,count1);
        if(type[temp] != count1)
            scc[num].push_back(temp);
    }
    color[num] = BLACK;
}
void transpostion()
{
    for(int i = 0;i < nodeNum;++i)
        for(auto pos = arr[i].begin(); pos != arr[i].end();++pos)
        {
            int temp = *pos;
            tparr[temp].push_back(i);
        }
}
int judge()
{
    DFS();
    vector<pair<int,int> > v;
    transpostion();
    for(int i = 0;i < nodeNum;++i)
    {
        v.push_back(make_pair(f[i],i));
        color[i] = WHITE;
    }
    sort(v.begin(),v.end());
    int count1 = 0;
    for(int i = nodeNum - 1;i >= 0;--i)
        if(color[v[i].second] == WHITE)
            DFStravel1(v[i].second,count1++);
    if(count1 == 1)
        return 1;
    for(int i = 0;i < nodeNum;++i)
    {
        int alNum;
        memset(color,WHITE,sizeof(color));
        if(color[i] == WHITE)
            alNum = DFStravel2(i);
        if(alNum == count1)
            return 1;
    }
    return 0;
}
int main()
{
    input();
    cout << judge();
    return 0;
}