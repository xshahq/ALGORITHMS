#include<bits/stdc++.h>
using namespace std;
void dfs(node* n)
{
    if(n)
    {
        cout << n->key << endl;
        node* temp = n->child;
        while(temp)
        {
            dfs(temp);
            temp = temp->brother;
        }
    }
}
void print(binarytree bt)
{
    dfs(bt.root);
}