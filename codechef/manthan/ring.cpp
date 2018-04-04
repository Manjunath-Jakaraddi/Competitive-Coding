#include<bits/stdc++.h>
using namespace std;
long long int n,p,q,r;
vector<long long int> v;
long long int dp[3];
int main()
{
	long long int mx=0;
	cin>>n>>p>>q>>r;
	for(long long int i=0;i<n;i++)
	{
		cin>>mx;
		v.push_back(mx);
	}
	dp[0]=p*v[0];
	dp[1]=dp[0]+q*v[0];
	dp[2]=dp[1]+r*v[0];
	for(long long int i=1;i<n;i++)
	{
		dp[0]=max(dp[0],p*v[i]);
		dp[1]=max(dp[1],dp[0]+q*v[i]);
		dp[2]=max(dp[2],dp[1]+r*v[i]);
	}
	cout<<dp[2]<<endl;
	cout<<sizeof(long long);
	return 0;
}
