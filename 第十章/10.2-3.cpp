#include<bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(){}
    node(int x) : data(x),next(nullptr){}
};
struct LIST
{
    node* head;
    node* tail;
    LIST() : head(nullptr),tail(nullptr){}
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
    if(!head)
        head = current;
    if(tail)
        tail ->next = current;
    tail = current;
}
int LIST :: DELETETAIL()
{
    if(head== nullptr)
        cout << "empty stack";
    else
    {
        node* current = head;
        head = current ->next;
        int temp = current ->data;
        delete current;
        return temp;
    }
}
struct QUEUE
{
    LIST l;
    QUEUE() : l(){}
    void ENQUEUE(int x);
    int DEQUEUE();
};
void QUEUE :: ENQUEUE(int x)
{
    l.INSERT(x);
}
int QUEUE ::DEQUEUE()
{
    return l.DELETETAIL();
}