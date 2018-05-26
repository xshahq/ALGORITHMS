#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* np;
    node(){}
    node(int x) : data(x),np(nullptr){}
};
struct LIST
{
    node* head;
    node* tail;
    LIST() : head(nullptr),tail(nullptr){}
    int DELETETAIL();
    void INSERT(int x);
};
void LIST :: INSERT(int x)
{
    node* newnode = new node(x);
    if(!head)
        head = newnode;
    if(tail)
    {
        tail ->np = (node*)((unsigned long long)tail ->np ^ (unsigned long long)newnode);
        newnode ->np = tail;
    }
    tail = newnode;
}
int LIST :: DELETETAIL()
{
    if(!tail)
        return -1;
    int temp = tail ->data;
    node* pre = tail ->np;
    if(pre)
        pre ->np = (node*)((unsigned long long)pre ->np ^ (unsigned long long)tail);
    delete tail;
    tail = pre;
    return temp;
}
void REVERSE(LIST& l)
{
    node* temp = l.head;
    l.head = l.tail;
    l.tail = temp;
}