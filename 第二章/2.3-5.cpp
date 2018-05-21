int binarysearch(int* arr,int length,int v) // length为数组长度，v为查找的数字
{
    int l = 0,r = length - 1,mid;
    while(l < r)
    {
        mid = (l + r) / 2;
        if(arr[mid] < v)
            l = mid + 1;
        else if(arr[mid] > v)
            r = mid - 1;
        else
            break;
    }
    if(l >= r)
        return -1;
    return mid;
}