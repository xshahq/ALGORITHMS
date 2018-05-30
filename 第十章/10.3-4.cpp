#include<bits/stdc++.h>
using namespace std;
#define M 100
int FREE = 0,arr[M][3];
void initalize()
{
    for(int i = 0;i < M - 1;++i)
    {
        arr[i][2] = i + 1;
        arr[i][1] = -1;
    }
    arr[M - 1][2] = -1;
    arr[M - 1][1] = -1;
}
void allocate(int x)
{
    if(FREE == -1)
        cout << "no space";
    else
    {
        int temp = FREE;
        arr[FREE][0] = x;
        FREE = arr[FREE][2];
        arr[FREE][1] = temp;
    }
}
void FREEOBJECT(int x)
{
    if(arr[FREE][1] == -1)
        cout << "it's empty";
    else
    {
        if(arr[x][1] != -1)
            arr[arr[x][1]][2] = arr[x][2];
        if(arr[x][2] != -1)
            arr[arr[x][2]][1] = arr[x][1];
        if(arr[FREE][1] != -1)
            arr[arr[FREE][1]][2] = x;
        arr[x][1] = arr[FREE][1];
        arr[x][2] = FREE;
        FREE = x;
    }
}