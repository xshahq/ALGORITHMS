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
        cout << nextpos << endl;
        QUICK_SORT(arr,l,nextpos - 1);
        QUICK_SORT(arr,nextpos + 1,r);

    }
}