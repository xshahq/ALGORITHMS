#include<bits/stdc++.h>
using namespace std;
int arr[100][100];//arr数组代表i检测j的结果
int judge(vector<int>& v)
{
    if(v.size() == 1)
        return v[0];
    vector<int> temp;
    for(int i = 0;i < v.size();i += 2)
    {
        int j = i + 1;
        if(arr[v[i]][v[j]] && arr[v[j]][v[i]])
            temp.push_back(v[i]);
    }
    return judge(temp);
}
void isbroken(int n)
{
    vector<int> v;
    int i;
    i = n % 2 ? 1 : 0;
    for(;i < n;++i)
        v.push_back(i);
    if(n % 2)
    {
        int count1 = 0;
        for(int i = 1;i < n;++i)
            if(arr[0][i] && arr[i][0])
                count1++;
        if(count1 >= n / 2)
            for(int i = 0;i < n;++i)
                if(arr[0][i])
                    cout << i + 1 << endl;
        return;
    }
    int temp = judge(v);
    for(int i = 0;i < n;++i)
        if(arr[temp][i])
            cout << i + 1 << endl;
}
