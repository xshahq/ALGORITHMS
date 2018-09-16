#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<list>
#include<queue>
#include<stack>
using namespace std;
#define WHITE 0
#define BLACK 1
#define GREY 2
#define N 100
list<int> arr[N];
int color[N],nodeNum,edge,time = 0,d[N],f[N];
void DFStravel(int);
void input()
{
    cin >> nodeNum >> edge;
    for(int i = 0;i < edge;++i)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        arr[temp1].push_back(temp2);
        //arr[temp2].push_back(temp1);
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
void travel(int num)
{
    color[num] = GREY;
    cout << num << " ";
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            travel(temp);
    }
    color[num] = BLACK;
}
void strongconnect()
{
    vector<pair<int,int> > v;
    for(int i = 0;i < nodeNum;++i)
    {
        pair<int,int> p(f[i],i);
        v.push_back(p);
        color[i] = WHITE;
    }
    sort(v.begin(),v.end());
    for(int i = 0;i < nodeNum;++i)
        if(color[v[i].second] == WHITE)
        {
            travel(v[i].second);
            cout << endl;
        }
}
int main()
{
    input();
    DFS();
    strongconnect();
    return 0;
}
