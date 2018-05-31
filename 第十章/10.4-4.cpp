#include<bits/stdc++.h>
using namespace std;
void dfs(node* n)
{
    if(n)
    {
        node* temp = n->child;
        while(temp)
        {
            cout << temp->key << endl;
            dfs(temp);
            temp = temp->brother;
        }
    }
}
void print(binarytree bt)
{
    cout << bt.root->key << endl;
    dfs(bt.root);
}