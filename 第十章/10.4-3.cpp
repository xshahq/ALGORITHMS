#include<bits/stdc++.h>
using namespace std;
vector<node*> v;//这里用vector作为栈
void print(binarytree bt)
{
    node* temp = bt.root;
    while(temp && v.size())
    {
        while(temp)
        {
            cout << temp->key<< endl;
            v.push_back(temp);
            temp = temp->l;
        }
        while(v.size() && !(temp->r))
        {
            v.pop_back();
            temp = *v.rbegin();
        }
        if(!v.size())
            break;
        temp = temp->r;
        v.pop_back();
        v.push_back(temp);
    }
}