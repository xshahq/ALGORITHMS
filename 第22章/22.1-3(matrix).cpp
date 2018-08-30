#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000
int arr[N][N],edge,node;
void input()
{
    cin >> node >> edge;
    for(int i = 0;i < edge;++i)
    {
        int head,tail;
        cin >> head >> tail;
        arr[head][tail] = 1;
    }
}
void transposition()
{
    for(int i = 1;i <= node;++i)
        for(int j = 1;j <= node;++j)
            if(arr[i][j])
            {
                if(!arr[j][i])
                {
                   if(j < i)
                        arr[i][j] = 0;
                   arr[j][i] = 1;
                }
                else if(i != j)
                {
                    arr[j][i] = 0;
                }
            }
}
void output()
{
    for(int i = 1;i <= node;++i)
    {
        for(int j = 1;j <= node;++j)
            cout << arr[i][j];
        cout << endl;
    }
}
int main()
{
    input();
    output();
    transposition();
    cout << endl;
    output();
    return 0;
}