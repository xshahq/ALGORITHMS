#include <iostream>
using namespace std;
int a[25][25],n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int j=1;j<=n;j++)
	{
		int r=0,w=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]==1)
				r++;
			else
				w++;
		}
		if(r>w)
			cout<<j<<" ";
	}
	return 0;
