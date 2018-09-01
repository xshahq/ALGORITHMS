#include <stdio.h>
#include<vector>
#include <stdlib.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 100
int node,edge,arr[N][N];
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
void output()
{
    for(int i = 1;i <= node;++i)
    {
        for(int j = 1;j <= node;++j)
            cout << arr[i][j];
        cout << endl;
    }
}
int judge()
{
    int i = 1;
    while(i <= node)
    {
        int temp = i;
        for(int j = 1;j <= node;++j)
            if(arr[i][j] && j != i)
            {
                i = j;
                break;
            }
        if(temp == i)
        {
            for(int j = 1;j <= node;++j)
            {
                if(arr[j][i] && i == j)
                    return 0;
                if(i != j && !arr[j][i])
                    return 0;
            }
            return 1;
        }
    }

}
int main()
{
    input();
    output();
    cout << endl;
    cout << judge();
    return 0;
}
