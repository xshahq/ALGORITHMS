#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
using namespace std;
#define WHITE 0
#define BLACK 1
#define GREY 2
#define N 100
list<int> arr[N];
int color[N],nodeNum,edge,time = 0,d[N],f[N],dp[N];
int DFStravel(int,int);
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
int DFS(int s,int t)
{
    int ans = 0;
    for(int i = 0;i < nodeNum;++i)
        color[i] = WHITE;
    ans += DFStravel(s,t);
    return ans;
}
int DFStravel(int num,int t)
{
    if(num == t)
        return 1;
    d[num] = time++;
    color[num] = GREY;
    int ret = 0;
    for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
    {
        int temp = *pos;
        if(color[temp] == WHITE)
            if(!dp[temp])
                dp[temp] = DFStravel(temp,t);
            ret += dp[temp];
    }
    color[num] = BLACK;
    f[num] = time++;
    return ret;
}
int main()
{
    input();
    int s,t;
    cin >> s >> t;
    cout << DFS(s,t);
    return 0;
}