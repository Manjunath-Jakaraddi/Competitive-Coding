#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long x,n;
	cin>>n;
	long long mx=0;
	while(n--)
	{
		cin>>x;
		double nf=sqrt(x);
	       	int ni=nf;
		if((nf-ni)!=0.0)	mx=max(mx,x);
	}
	cout<<mx<<endl;
	return 0;
}
