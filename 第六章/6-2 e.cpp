#include<bits/stdc++.h>
using namespace std;
int d;//d叉堆
void INCREASE_KEY(int* arr,int i,int k)
{
    if(arr[i] > k)
        cout << "error";
    else
    {
        arr[i] = k;
        while(i)
        {
            int parent;
            parent = (i - 1) / d;
            if(arr[parent] > arr[i])
                break;
            swap(arr[i],arr[parent]);
            i = parent;
        }
    }
}