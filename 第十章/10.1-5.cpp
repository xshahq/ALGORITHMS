#include<bits/stdc++.h>
using namespace std;
#define N 100
int arr[N];
struct QUEUE
{
    int tail,head;
};
int ENQUEUETAIL(QUEUE& q,int x)
{
    if((!q.head && q.tail == N -1) || q.head - 1 == q.tail)
        return -1;
    arr[q.tail] = x;
    if(q.tail == N - 1)
        q.tail = 0;
    else
        q.tail += 1;
    return q.tail;
}
int ENQUEUEHEAD(QUEUE& q,int x)
{
    if((!q.head && q.tail == N -1) || q.head - 1 == q.tail)
        return -1;
    if(!q.head)
        q.head = N -1;
    else
        q.head -= 1;
    return q.head;
}
int DEQUEUEHEAD(QUEUE& q)
{
    if(q.head == q.tail)
        return -1;
    int x = arr[q.head];
    if(q.head == N -1)
        q.head = 0;
    else
        q.head += 1;
    return  x;
}
int DEQUEUETAIL(QUEUE& q)
{
    if(q.head == q.tail)
        return -1;
    if(!q.tail)
        q.tail = N - 1;
    else
        q.tail -= 1;
    return arr[q.tail];
}