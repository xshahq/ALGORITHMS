#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define WHITE 0
#define BLACK 1
#define GREY 2
#define N 100
list<int> arr[N];
list<int> tparr[N];
int color[N],nodeNum,edge,time = 0,d[N],f[N],isHalfConnect[N];
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
void DFStravel1(int num)
{
    color[num] = GREY;
    for(auto pos = tparr[num].begin();pos != tparr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
        {
            DFStravel(temp);
            isHalfConnect[num] = 1;
            isHalfConnect[temp] = 1;
        }
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
        isHalfConnect[i] = 0;
        color[i] = WHITE;
    }
    sort(v.begin(),v.end());
    for(int i = nodeNum - 1;i >= 0;--i)
        if(color[v[i].second] == WHITE)
            DFStravel1(v[i].second);
    for(int i = nodeNum - 1;i >= 0;--i)
        if(isHalfConnect[i])
            return 0;
    return 1;
}
int main()
{
    input();
    cout << judge() << endl;
    return 0;
}