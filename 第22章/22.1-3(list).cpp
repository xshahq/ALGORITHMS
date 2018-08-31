#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100
int nodeNum,edge;
struct node
{
    int data;
    node* next;
    node(int d,node* n) : data(d),next(n){};
};
node* arr[N];
void input()
{
    cin >> nodeNum >> edge;
    for(int i = 1;i <= nodeNum;++i)
        arr[i] = nullptr;
    for(int i = 0;i < edge;++i)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        node* temp = new node(temp2,arr[temp1]);
        arr[temp1] = temp;
    }
}
void output()
{
    for(int i = 1;i <= nodeNum;++i)
    {
        node* temp = arr[i];
        while(temp)
        {
            cout << temp ->data;
            temp = temp ->next;
        }
        cout << endl;
    }
}
void transposition()
{
    node* beg[N];
    for(int i = 1;i <= nodeNum;++i)
    {
        beg[i] = arr[i];
        arr[i] = nullptr;
    }
    for(int i = 1;i <= nodeNum;++i)
    {
        node* temp = beg[i];
        while(temp)
        {
            int t = temp ->data;
            node* temp1 = new node(i,arr[t]);
            arr[t] = temp1;
            temp = temp ->next;
        }
    }
    for(int i = 1;i <= nodeNum;++i)
    {
        node* temp = beg[i];
        while(temp)
        {
            node* current = temp;
            temp = temp ->next;
            delete current;
        }
    }
}
int main()
{
    input();
    output();
    transposition();
    output();
    return 0;
}