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
int color[N],nodeNum,edge;
int DFStravel(int);
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
int DFS()
{
    for(int i = 0;i < nodeNum;++i)
        color[i] = WHITE;
    for(int i = 0;i < nodeNum;++i)
    {
        for(int j = 0;j < nodeNum;++j)
            color[j] = WHITE;
        if(!DFStravel(i))
            return 0;
    }
    return 1;
}
int DFStravel(int num)
{
    color[num] = GREY;
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
        {
            if(!DFStravel(temp))
                return 0;
        }
        else if(color[temp] == BLACK)
            return 0;
    }
    color[num] = BLACK;
    return 1;
}
int main()
{
    input();
    DFS() ? cout << "it's a single connect graph" << endl : cout << " it's not a single graph" << endl;
    return 0;
}