#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
#define WHITE 0
#define GREY 1
#define N 100
int arr[N][N],edge,node,color[N],d[N];
void input()
{
    cin >> node >> edge;
    for(int i = 0;i < edge;++i)
    {
        int head,tail;
        cin >> head >> tail;
        arr[head][tail] = 1;
        arr[tail][head] = 1;
    }
}

void output()
{
    for(int i = 1;i <= node;++i)
    {
        for(int j = 1;j <= node;++j)
            cout << arr[i][j];
        cout << endl;
    }
}
void BFS()
{
    for(int i = 1;i <= node;++i)
    {
        color[i] = WHITE;
        d[i] = INT_MAX;
    }
    queue<int> qe;
    qe.push(1);
    color[1] = GREY;
    d[1] = 0;
    while(qe.size())
    {
        int num = qe.front();
        for(int i = 1;i <= node;++i)
            if(arr[num][i] && color[i] == WHITE)
            {
                qe.push(i);
                color[i] = GREY;
                d[i] = d[num] + 1;
            }
        qe.pop();
    }
}
int main()
{
    input();
    //output();
    BFS();
    for(int i = 1;i <= node;++i)
        cout << d[i] << endl;
    return 0;
}