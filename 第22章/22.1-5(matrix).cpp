#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100
int arr[N][N],edge,node,arr2[N][N];//arr2为arr的平方图
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
            cout << arr2[i][j];
        cout << endl;
    }
}
void computesquar()
{
    for(int i = 1;i <= node;++i)
        for(int j = 1;j <= node;++j)
            if(arr[i][j])
                arr2[i][j] = 1;
            else
                for(int k = 1;k <= node;++k)
                    if(arr[i][k] && arr[k][j])
                        arr2[i][j] = 1;
}
int main()
{
    input();
    computesquar();
    output();
    return 0;
}
