#include<bits/stdc++.h>
using namespace std;
void MAX_HEAP(int* arr,int i,int length)
{
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
}
int main()
{
    int arr[10] = {3,1,4,6,2,7,9,8,0,5};
    MAX_HEAP(arr,0,10);
    cout << arr[0];
    return 0;
}