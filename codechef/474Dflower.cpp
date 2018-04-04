#include<bits/stdc++.h>
#define max 1000000007
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
long long a[1000005];
int main()
{
  	int n,k;
	cin>>n>>k;
	long long cnt=0;
	a[0]=1;
	for(int i=1;i<=100005;i++)
	{
		int z=k;
		if(i<k)
			a[i]=1;
		else
			a[i]=(a[i-1]+a[i-k])%max;
	}
	for(int i=1;i<100005;i++)
	{
		a[i]+=a[i-1];
		a[i]%=max;
	}
	int x,y;
	while(n--)
	{
		cin>>x>>y;
		cout<<((a[y]-a[x-1])+max)%max<<endl;
	} 
 	return 0;
}
