#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<list>
#include<queue>
using namespace std;
#define WHITE 0
#define GREY 1
#define N 100
#define GOOD 1
#define BAD 0
list<int> arr[N];
int color[N],d[N],nodeNum,edge,property[N];
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
int BFS()
{
    for(int i = 0;i < nodeNum;++i)
    {
        d[i] = INT_MAX;
        color[i] = WHITE;
    }
    queue<int> qe;
    qe.push(0);
    d[0] = 0;
    color[0] = GREY;
    property[0] = GOOD;
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
                property[n] = property[num] == GOOD ? BAD : GOOD;
            }
            else
                if(property[n] == property[num])
                    return 0;//0表示无法进行划分
        }
        qe.pop();
    }
    return 1;//1代表可以这样划分
}
int main()
{
    input();
    //output();
    cout << BFS();
    return 0;
}