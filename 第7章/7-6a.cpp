#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a;
	int b;
};
void swap(node& a,node& b)
{
	node temp=a;
	a=b;
	b=temp;
}
node PARTITION(node a[],int l,int r)
{
    node x=a[r],ret;
	int i=l-1;
	int j=r+1;
	int k=l;
	while(k<j && k<=r)
	{
		if(a[k].b<x.a)
		{
			++i;
			swap(a[i],a[k]);
			++k;
		}
		else if(a[k].a>x.a) 
		{
			j--;
			swap(a[j],a[k]);
		}
		else 
		{
			x.a=max(a[k].a,x.a);
			x.b=min(a[k].b,x.b); 
			++k;
		}
	}
	ret.a=i;
	ret.b=j;
	return ret;
}
void Fuzzy_sort(node a[],int l,int r)
{
	if(l<r)
	{
		node mid=partition(a,l,r);//mid保存分割点[i,j]
		//中间重叠部分不处理，只处理两头部分
		Fuzzy_sort(a,l,mid.a);
		Fuzzy_sort(a,mid.b,r);
	}
}