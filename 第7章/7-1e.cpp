#include<bits/stdc++.h>
using namespace std;
int HOARE_PARTTION(int* arr,int l,int r)
{
    int temp = arr[r];
    int i = l - 1,j = r + 1;
    while(i < j)
    {
        i++;
        j--;
        while(arr[i] < temp)
            ++i;
        while(arr[j] > temp)
            --j;
        if(i < j)
            swap(arr[i],arr[j]);
    }
    if(arr[l] == temp)
        swap(arr[l],arr[j]);
    return j;
}
void QUICK_SORT(int* arr,int l,int r)
{
    if(l < r)
    {
        int nextpos = HOARE_PARTTION(arr,l,r);
        QUICK_SORT(arr,l,nextpos - 1);
        QUICK_SORT(arr,nextpos + 1,r);
    }
}
//测试数据
int main()
{
    int arr[10] = {1,4,3,9,1,1,4,1,2,1};
    QUICK_SORT(arr,0,9);
    for(int i = 0;i < 10;++i)
        cout << arr[i];
    return 0;
}