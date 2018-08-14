#include<bits/stdc++.h>
using namespace std;
void findx(int* arr,int length,int x)
{
    sort(arr,arr + length);
    int i = 0,j = length - 1,count1 = 0;
    while(i < j)
    {
        if(arr[i] + arr[j] < x)
            ++i;
        else if(arr[i] + arr[j] > x)
            --j;
        else
        {
            count1 = 1;
            cout << i++ << " " << j-- << endl;
        }
    }
    if(!count1)
        cout << "can't find" << endl;
}
int main()
{
    int arr1[5] = {1,2,3,4,5};
    findx(arr1,5,1);
    findx(arr1,5,4);
    findx(arr1,5,10);
    findx(arr1,5,9);
}