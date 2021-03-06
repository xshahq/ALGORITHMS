#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;
#define WHITE 0
#define GREY 1
#define N 100
list<int> arr[N];
int color[N],d[N],nodeNum,edge;
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
void BFS(int temp)
{
    for(int i = 0;i < nodeNum;++i)
    {
        d[i] = INT_MAX;
        color[i] = WHITE;
    }
    queue<int> qe;
    qe.push(temp);
    d[temp] = 0;
    color[temp] = GREY;
    while(qe.size())
    {
        int num = qe.front();
        for(auto pos = arr[num].begin();pos != arr[num].end();++pos)
        {
            int n = *pos;
            if(color[n] == WHITE)
            {
                qe.push(n);
                d[n] = d[num] + 1;
                color[n] = GREY;
            }
        }
        qe.pop();
    }
}
int diameter()
{
    int max1 = INT_MIN,count1;
    BFS(0);
    for(int i = 0;i < nodeNum;++i)
        if(max1 < d[i])
        {
            max1 = d[i];
            count1 = i;
        }
    BFS(count1);
    max1 = INT_MIN;
    for(int i = 0;i < nodeNum;++i)
        max1 = max(max1,d[i]);
    return max1;
}
int main()
{
    input();
    //output();
    cout << diameter();
    return 0;
}
