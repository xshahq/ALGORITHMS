#include<vector>
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
int color[N],nodeNum,edge,father[N];
int DFStravel(int);
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
            father[temp] = num;
            if(!DFStravel(temp))
                return 0;
        }
        else if(color[temp] == GREY && father[num] != temp)
            return 0;
    }
    color[num] = BLACK;
    return 1;
}
int main()
{
    input();
    DFS() ? cout << "it's a direct graph" << endl : cout << " it's not adirect graph" << endl;
    return 0;
}
