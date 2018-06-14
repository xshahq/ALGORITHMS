#include<bits/stdc++.h>
using namespace std;
int arr[100][100];//Young  yableau
void init()
{
    for(int i = 0;i < 100;++i)
        for(int j = 0;j < 100;++j)
            arr[i][j] = INT_MAX;
}
void MIN(int i,int j,int m,int n)
{
    int r = i + 1,d = j + 1,temp = arr[i][j];
    if(r < m && arr[r][j] < temp)
        temp = arr[r][j];
    if(d < n && arr[i][d] < temp)
        temp = arr[i][d];
    if(temp != arr[i][j])
    {
        if(temp == arr[r][j])
        {
            swap(arr[i][j],arr[r][j]);
            MIN(r,j,m,n);
        }
        else
        {
            swap(arr[i][j],arr[i][d]);
            MIN(i,d,m,n);
        }
    }
}
int EXTRACT_MIN(int m,int n)
{
    int temp = arr[0][0];
    arr[0][0] = INT_MAX;
    MIN(0,0,m,n);
    return temp;
}
void TO_POS(int i,int j,int num)
{;
    int l = i - 1,up = j - 1,temp = arr[i][j];
    if(l >= 0 && arr[l][j] > arr[i][j])
        temp = arr[l][j];
    if(up >= 0 && arr[i][up] > temp)
        temp = arr[i][up];
    if(temp != arr[i][j])
    {
        if(temp == arr[l][j])
        {
            swap(arr[i][j],arr[l][j]);
            TO_POS(l,j,num);
        }
        else
        {
            swap(arr[i][j],arr[i][up]);
            TO_POS(i,up,num);
        }
    }
}
void INSERT(int n,int m,int num)
{
    if(arr[n - 1][m - 1] != INT_MAX)
        cout << "it's full" << endl;
    else
    {
        arr[n- 1][m - 1] = num;
        TO_POS(n - 1,m - 1,num);
    }
}
void SORT(int* a,int length)
{
    int temp = sqrt(length);
    for(int i = 0;i < length;++i)
        INSERT(temp,temp,a[i]);
    for(int i = 0;i < length;++i)
    {
        a[i] = EXTRACT_MIN(temp,temp);
    }
}