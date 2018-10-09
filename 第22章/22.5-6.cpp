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
list<int> componentSet[N];
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
void DFStravel1(int num,int count1)
{
    color[num] = GREY;
    type[num] = count1;
    componentSet[count1].push_back(num);
    for(auto pos = tparr[num].begin();pos != tparr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            DFStravel1(temp,count1);
    }
    for(auto pos = tparr[num].begin();pos != tparr[num].end();)
    {
        int temp = *pos;
        if(type[temp] == count1)
            pos = arr[num].erase(pos);
        else
            ++pos;
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
void newGraph(int count1)
{
    auto pos1 = componentSet[count1].begin();
    auto pos2 = ++pos1;
    --pos1;
    for(;pos2 != componentSet[count1].end();++pos2)
    {
        tparr[*pos1].push_back(*pos2);
        ++pos1;
    }
    tparr[*pos1].push_back(*componentSet[count1].begin());
}
void output();
void other()
{
    DFS();
    transpostion();
    //output();
    vector<pair<int,int> > v;
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
    for(int i = 0;i < count1;++i)
        newGraph(i);
}
void output()
{
    for(int i = 0;i < nodeNum;++i)
    {
        for(auto pos = tparr[i].begin();pos != tparr[i].end();++pos)
            cout << *pos;
        cout << endl;
    }
}
int main()
{
    input();
    other();
    output();
    return 0;
}