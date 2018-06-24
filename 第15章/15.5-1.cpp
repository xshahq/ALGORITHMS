#include<bits/stdc++.h>
using namespace std;
#define N 100
void CONSTRUCT_OPTIMAL_BST(int (*rt)[N],int l,int r)
{
    cout << "k" << rt[l][r] << endl;
    if(l < r)
    {
        CONSTRUCT_OPTIMAL_BST(rt,l,rt[l][r] - 1);
        CONSTRUCT_OPTIMAL_BST(rt,rt[l][r] + 1,r);
    }
    else
    {
        cout << "d"<< count1++ << endl;
        cout<< "d" << count1++ << endl;
    }
}