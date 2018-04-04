#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[10];
	for(int i=0;i<8;i++)
		cin>>a[i];
	int mx=0,maxsofar=0;
	for(int i=0;i<8;i++)
	{
		maxsofar=maxsofar+a[i];
		mx=max(mx,maxsofar);
		if(maxsofar<0)	maxsofar=0;
	}
	cout<<mx<<endl;
	return 0;
}
