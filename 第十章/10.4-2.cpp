using namespace std;
#include<bits/stdc++.h>
using namespace std;
void dfs(node* n)
{
    if(n)
    {
        cout << n->key << endl;
        dfs(n->l);
        dfs(n->r);
    }
}
void print(binarytree bt)
{
    node* temp = bt.root;
    dfs(temp);
}