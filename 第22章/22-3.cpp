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
int color[N],nodeNum,edge,time = 0,d[N],f[N],degree[N];
list<pair<int,int> > edge1;
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
void DFStravel(int num,int target)
{
    if(num == target)
        return;
    auto pos = arr[num].begin();
    while(pos != arr[num].end())
    {
        int num1 = *pos;
        edge1.push_back(make_pair(num,num1));
        pos = arr[num].erase(pos);
        DFStravel(num1,target);
        target = num;
    }
}
void eular()
{
    auto pos  = arr[0].begin();
    while(pos != arr[0].end())
    {
        int num = *pos;
        edge1.push_back(make_pair(0,num));
        pos = arr[0].erase(pos);
        DFStravel(num,0);

    }
}
int main()
{
    input();
    eular();
    for(auto pos = edge1.begin();pos != edge1.end();++pos)
        cout << pos ->first << pos ->second << endl;
    return 0;
}