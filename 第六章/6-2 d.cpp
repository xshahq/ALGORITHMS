#include<bits/stdc++.h>
using namespace std;
int d;
void INCREASE_KEY(vector<int>& arr,int i,int k)
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
void INSERT(vector<int>& v,int num)
{
    v.push_back(num);
    int length = v.size();
    INCREASE_KEY(v,length - 1,num);
}