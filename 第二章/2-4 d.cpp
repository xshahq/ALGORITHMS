int Merge(int* arr,int l,int mid,int r,int* arr2)
{
    for(int i = l;i <= r;++i)
        arr2[i] = arr[i];
    int i = l,j = mid + 1,t = l,ans = 0;
    while(i <= mid && j <= r)
    {
        if(arr2[i] < arr2[j])
            arr[t++] = arr2[i++];
        else
        {
            arr[t++] = arr2[j++];
            ++ans;
        }
    }
    if(i <= mid)
        while(t <= r)
            {
                arr[t++] = arr2[i++];
                ans = ans + r - mid + 1;
            }
    else
        while(t <= r)
            arr[t++] = arr2[j++];
    return ans;
}
int reverseorderpair(int* arr,int l,int r)
{
    if(l >= r)
        return 0;
    int mid = (l + r) / 2;
    int temp1 = reverseorderpair(arr,l,mid),temp2 = reverseorderpair(arr,mid + 1,r);
    int* arr2 = new int[r - l + 1];
    int temp3 = Merge(arr,l,mid,r,arr2);
    delete[] arr2;
    return temp1 + temp2 + temp3;
}