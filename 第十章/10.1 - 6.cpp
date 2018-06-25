#include<bits/stdc++.h>
using namespace std;
struct QUEUE
{
    vector<int> v1,v2;//这里用vector来表示栈
};
void ENQUEUE(QUEUE& q,int x)
{
    while(q.v2.size())
    {
        q.v1.push_back(q.v2.back());
        q.v2.pop_back();
    }
    q.v1.push_back(x);
}
int DEQUEUE(QUEUE& q)
{
    while(q.v1.size())
    {
        q.v2.push_back(q.v1.back());
        q.v1.pop_back();
    }
    if(!q.v2.size())
        return -1;
    int temp = q.v2.back();
    q.v2.pop_back();
    return temp;
}