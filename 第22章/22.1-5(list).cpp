#include<vector>
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
#define N 100
list<int> arr[N],arr2[N];
int nodeNum,edge;
void input()
{
    cin >> nodeNum >> edge;
    for(int i = 0;i < edge;++i)
    {
        int temp1,temp2;
        cin >> temp1 >> temp2;
        arr[temp1].push_back(temp2);
    }
}
void output()
{
    for(int i = 0;i < nodeNum;++i)
    {
        for(auto pos = arr2[i].begin();pos != arr2[i].end();++pos)
            cout << *pos;
        cout << endl;
    }
}
void computesquar()
{
    for(int i = 0;i < nodeNum;++i)
        for(auto pos = arr[i].begin();pos != arr[i].end();++pos)
        {
            int num = *pos;
            arr2[i].push_back(num);
            for(auto pos1 = arr[num].begin();pos1 != arr[num].end();++pos1)
                arr2[i].push_back(*pos1);
        }
}
int main()
{
    input();
    computesquar();
    output();
    return 0;
}