#include<bits/stdc++.h>
using namespace std;
void DELECT(int* arr,int j,int& length)
{
    if(j >= length)
        cout << "errow";
    else
    {
        arr[j] = INT_MIN;
        int i = j;
        while(1)
        {
            int l = 2 * i + 1,r = 2 * i + 2,temp = i;
            if(l < length)
                temp = arr[temp] > arr[l] ? temp : l;
            if(r < length)
                temp = arr[temp] > arr[r] ? temp : r;
            if(temp == i)
                break;
            swap(arr[temp],arr[i]);
            i = temp;
        }
        --length;
        if(j < length)
            swap(arr[j],arr[length]);
    }
}