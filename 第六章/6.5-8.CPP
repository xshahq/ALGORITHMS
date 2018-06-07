#include<bits/stdc++.h>
using namespace std;
struct QUEUE
{
    int num;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    QUEUE() : num(0){}
    void PUSH(int n);
    void POP();
};
void QUEUE::PUSH(int n)
{
    pair<int,int> p(++num,n);
    pq.push(p);
}
void QUEUE::POP()
{
    if(!num)
        cout << "queue is empty";
    else
    {
        cout << pq.top().second;
        pq.pop();
        --num;
    }
}