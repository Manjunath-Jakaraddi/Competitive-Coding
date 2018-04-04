#include<bits/stdc++.h>
using namespace std;
map<long long,long long> dp;
long long solve(long long n)
{
	if(n==0)	return 0;
	if(dp[n]!=0)	return dp[n];
	return dp[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
}
int main()
{
	long long n;
	while(cin>>n)
	{
		cout<<(1LL*solve(n))<<endl;
	}
	return 0;
}
