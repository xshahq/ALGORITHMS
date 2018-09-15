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
int color[N],nodeNum,edge,time = 0,d[N],f[N],degree[N];
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
        degree[temp]++;
        if(color[temp] == WHITE)
            DFStravel(temp);
    }
    color[num] = BLACK;
    f[num] = time++;
}
void deletenode(int num)
{
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
        degree[*pos]--;

}
void toplogical()
{
    int count1 = N;
    while(count1)
    {
        for(int i = 0;i < nodeNum;++i)
            if(!degree[i])
            {
                cout << i << endl;
                degree[i]--;
                deletenode(i);
                break;
            }
        --count1;
    }
}
int main()
{
    input();
    DFS();
    toplogical();
    return 0;
}