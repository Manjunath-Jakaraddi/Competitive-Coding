#include<bits/stdc++.h>
using namespace std;
long long int a[500005],d[500005],dp[500005][2];
int main()
{
	int n;
	cin>>n;
	long long sum=0,mx=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i>0)
		{
			d[i]=abs(a[i]-a[i-1]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=max(d[i],dp[i-1][1]+d[i]);
		dp[i][1]=max(-d[i],dp[i-1][0]-d[i]);
		mx=max(dp[i][1],max(dp[i][0],mx));	
	}
	cout<<mx;
	return 0;
}
