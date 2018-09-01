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
        node* n1 = new node(temp1,arr[temp2]);
        arr[temp1] = temp;
        arr[temp2] = n1;
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
void DELETE()
{
    for(int i = 1;i <= nodeNum;++i)
    {
        int d[N] = {0};
        d[i] = 1;
        node* temp = arr[i];
        node* pre = nullptr;
        while(temp)
            if(d[temp ->data])
            {
                node* current = temp;
                pre ? pre ->next = temp ->next : arr[i] = temp ->next;
                temp = temp ->next;
                delete current;
            }
            else
            {
                d[temp ->data]++;
                pre = temp;
                temp = temp ->next;
            }
    }
}
int main()
{
    input();
    output();
    cout << endl;
    DELETE();
    output();
    return 0;
}