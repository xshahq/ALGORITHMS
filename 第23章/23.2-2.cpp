#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<memory>
using namespace std;
#define N 1000
int arr[N][N],edge,node;
void input()
{
    cin >> node >> edge;
    for(int i = 0;i < edge;++i)
    {
        int head,tail,weight;
        cin >> head >> tail >> weight;
        arr[head][tail] = weight;
        arr[tail][head] = weight;
    }
}
int tree[N];
void prim()
{
    int w[N],n = -1;
    for(int i = 0;i < node;++i)
        w[i] = INT_MAX;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(INT_MIN,0));
    while(pq.size())
    {
        pair<int,int> p = pq.top();
        int temp = p.second;
        pq.pop();
        if(w[temp] == INT_MIN)
            continue;
        if(n >=0)
            tree[n] = temp;
        n = temp;
        w[temp] = INT_MIN;
        for(int i = 0;i < node;++i)
            if(arr[temp][i] && w[i] != INT_MIN && arr[temp][i] < w[i])
            {
                w[i] = arr[temp][i];
                pq.push(make_pair(arr[0][i],i));
            }
    }
}
int main()
{
    input();
    prim();
    int i = 0;
    cout << i << endl;
    while(tree[i])
    {
        cout << tree[i] << endl;
        i = tree[i];
    }
    return 0;
}