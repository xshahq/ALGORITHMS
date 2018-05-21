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
            cout << i << j << endl;
            ++i;
            --j;
        }
    }
    if(!count1)
        cout << "can't find";
}