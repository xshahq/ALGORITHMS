#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
void MIN_HEAP(int* arr,int i,int length)
{
    int l = 2 * i + 1,r = 2 * i + 2,temp = i;
    if(l < length)
        temp = arr[temp] < arr[l] ? temp : l;
    if(r < length)
        temp = arr[temp] < arr[r] ? temp : r;
    if(temp != i)
    {
        swap(arr[i],arr[temp]);
        MIN_HEAP(arr,temp,length);
    }
}