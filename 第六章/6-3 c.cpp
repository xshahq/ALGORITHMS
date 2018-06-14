#include<bits/stdc++.h>
using namespace std;
int arr[100][100];//Young  yableau
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