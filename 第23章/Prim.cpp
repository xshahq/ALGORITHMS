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
    int index;
    int t;
};
struct cmp
{
    int operator()(minEdge* a,minEdge* b)
    {
        return (a-> t) > (b-> t);
    }
};
int tree[N];//存放最小生成树的节点
void Prim()
{
    minEdge nodeArr[N];
    for(int i = 0;i < nodeNum;++i)
    {
        nodeArr[i].t = INT_MAX;
        nodeArr[i].index = i;
    }
    int isTraveled[N];
    memset(isTraveled,0,sizeof(isTraveled));
    isTraveled[0] = 1;
    priority_queue<minEdge*,vector<minEdge*>,cmp> pq;
    node* temp = arr[0];
    tree[0] = 0;
    while(temp)
    {
        if(!isTraveled[temp ->data])
            nodeArr[temp ->data].t = temp ->weight;
        temp = temp ->next;
    }
    for(int i = 1;i < nodeNum;++i)
        pq.push(nodeArr + i);
    int count1 = 1;
    while(pq.size())
    {
        minEdge* top = pq.top();
        int i = top ->index;
        tree[count1++] = i;
        isTraveled[i] = 1;
        temp = arr[i];
        while(temp)
        {
            if(!isTraveled[temp ->data])
                nodeArr[temp ->data].t = min(nodeArr[temp ->data].t,temp ->weight);
            temp = temp ->next;
        }
        pq = priority_queue<minEdge*,vector<minEdge*>,cmp>();
        for(int i = 0;i < nodeNum;++i)
            if(!isTraveled[i])
                pq.push(nodeArr + i);
    }
}
int main()
{
    input();
    Prim();
    for(int i = 0;i < nodeNum;++i)
        cout << tree[i] << endl;
 	return 0;;
}