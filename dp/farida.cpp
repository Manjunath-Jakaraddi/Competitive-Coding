#include<bits/stdc++.h>
using namespace std;
long dp[10004];
int main()
{
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		int n;
		cin>>n;
		if(n==0)
		{
			cout<<"Case "<<k<<": 0"<<endl;
			continue;
		}
		vector<unsigned long long> v(n+1);
		for(int i=1;i<=n;i++)	cin>>v[i];
		unsigned long long  dp[10004];
		dp[1]=v[1];
		long long  ans;
		for(int i=2;i<n;i++)	dp[i]=max(dp[i-2]+v[i],dp[i-1]);
		cout<<"Case "<<k<<": "<<dp[n-1]<<endl;
	}
	return 0;
}
