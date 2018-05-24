#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node* pre;
    node(){}
    node(int x) : data(x),next(nullptr),pre(nullptr){}
};
struct LIST
{
    node* head;
    LIST()
    {
        head = nullptr;
    }
    node* newnode(int x);
    int DELETETAIL();
    void INSERT(int x);
};
node* LIST :: newnode(int x)
{
    node* n = new node(x);
    return n;
}
void LIST :: INSERT(int x)
{
    node* current = newnode(x);
    if(head)
    {
        head ->next = current;
        current ->pre = head;
    }
    head = current;
}
int LIST :: DELETETAIL()
{
    if(head== nullptr)
        cout << "empty stack";
    else
    {
        node* current = head;
        head = current ->pre;
        int temp = current ->data;
        delete current;
        return temp;
    }
}
struct STACK
{
    LIST l;
    void PUSH(int x);
    int POP();
};
void STACK :: PUSH(int x)
{
    l.INSERT(x);
}
int STACK :: POP()
{
    return l.DELETETAIL();
}