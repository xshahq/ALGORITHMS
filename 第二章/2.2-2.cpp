void exchange(int* arr,int n)
{
    for(int i = 0;i < n;++i)
    {
        int min1 = arr[i],count1 = i;
        for(int j = i;j < n;++j)
            if(arr[j] < min1)
            {
                count1 = j;
                min1 = arr[j];
            }
        int temp = arr[count1];
        arr[count1] = arr[i];
        arr[i] = temp;
    }
}