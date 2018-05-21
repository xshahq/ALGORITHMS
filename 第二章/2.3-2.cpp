void Merge(int l,int r,int mid,int* arr,int* arr2)
{
    for(int i = l;i <= r;++i)
        arr2[i] = arr[i];
    int i = l,j = mid + 1,t = l;
    while(i <= mid && j <= r)
        if(arr2[j] > arr2[i])
            arr[t++] = arr2[i++];
        else
            arr[t++] = arr2[j++];
    int count1;
    if(i <= mid)
        count1 = i;
    if(j <= r)
        count1 = j;
    while(t <= r)
        arr[t++] = arr2[count1++];
}