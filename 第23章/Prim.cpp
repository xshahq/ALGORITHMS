#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<memory>
#include<climits>
using namespace std;
#define N 100
int nodeNum,edge;
struct node
{
    int data,weight;
    node* next;
    node(int d,int w,node* n) : data(d),weight(w),next(n){}
};
node* arr[N];
void input()
{
    cin >> nodeNum >> edge;
    for(int i = 1;i <= nodeNum;++i)
        arr[i] = nullptr;
    for(int i = 0;i < edge;++i)
    {
        int temp1,temp2,temp3;
        cin >> temp1 >> temp2 >> temp3;
        node* t1 = new node(temp2,temp3,arr[temp1]);
        node* t2 = new node(temp1,temp3,arr[temp2]);
        arr[temp1] = t1;
        arr[temp2] = t2;
    }
}
void output()
{
    for(int i = 0;i < nodeNum;++i)
    {
        node* temp = arr[i];
        while(temp)
        {
            printf("节点%d和%d,权重为%d\n",i,temp ->data,temp ->weight);
            temp = temp ->next;
        }
    }
}
class minEdge//定义一个类表示每个节点的到最小生成树的权重的最小值
{
public:
    int beg,en,weight;
    minEdge(int b,int e,int w):beg(b),en(e),weight(w){}
};
struct cmp
{
    int operator()(minEdge& a,minEdge& b)
    {
        return (a.weight) > (b.weight);
    }
};
int tree[N];//存放最小生成树的节点
void Prim()
{
    priority_queue<minEdge,vector<minEdge>,cmp> pq;
    tree[0] = 0;
    int visited[N];
    memset(visited,0,sizeof(visited));
    visited[0] = 1;
    node* temp = arr[0];
    int count1 = 1;
    while(temp)
    {
        minEdge me = minEdge(0,temp->data,temp->weight);
        pq.push(me);
        temp = temp->next;
    }
    while(pq.size())
    {
        minEdge top = pq.top();
        if(visited[top.en])
        {
            pq.pop();
            top = pq.top();
            continue;
        }
        tree[count1] = top.en;
        visited[top.en] = 1;
        temp = arr[tree[count1++]];
        while(temp)
        {
            minEdge me = minEdge(0,temp->data,temp->weight);
            pq.push(me);
            temp = temp->next;
        }
    }
}
int main()
{
    input();
    Prim();
    for(int i = 0;i < nodeNum;++i)
        cout << tree[i] << endl;
 	return 0;
}
