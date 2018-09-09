#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;
#define WHITE 0
#define BLACK 1
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
        arr[temp2].push_back(temp1);
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
    color[num] = BLACK;
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            DFStravel(temp);
    }
    f[num] = time++;
}
int main()
{
    input();
    DFS();
    for(int i = 0;i < nodeNum;++i)
        cout << d[i] << " " << f[i] << endl;
    return 0;
}