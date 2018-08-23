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
int main()
{
    int arr[10] = {3,1,4,6,2,7,9,8,0,5};
    MIN_HEAP(arr,0,10);
    cout << arr[0];
    return 0;
}
