#include<bits/stdc++.h>
using namespace std;
void print(binarytree bt)
{
    node* pre = nullptr;
    node* current = bt.root;
    while(current)
    {
        if(pre == current->parent)
        {
            cout << current->key << endl;
            pre = current;
            current = current->left ? current->left : current->right ? current->right : current->parent;
        }
        else if(pre == current->left && current->right)
        {
            pre = current;
            current = current->right;
        }
        else
        {
            pre = current;
            current = current->parent;
        }
    }
}