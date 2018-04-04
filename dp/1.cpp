#include<bits/stdc++.h>
using namespace std;
string s;
int dp[6200][6200];
int solve(int l,int r)
{
	if(l>r)	return 0;
	if(s[l]!=s[r])
	{
		
		if(!dp[l+1][r])	dp[l+1][r]=solve(l+1,r);
		if(!dp[l][r-1])	dp[l][r-1]=solve(l,r-1);
		return (dp[l][r]=1+min(dp[l+1][r],dp[l][r-1]));
		
	}
	else
	{
		if(!dp[l+1][r-1])	dp[l+1][r-1]=solve(l+1,r-1);
		return (dp[l][r]=dp[l+1][r-1]);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>s;
		cout<<solve(0,s.length()-1)<<endl;
		memset(dp,0,6200*6200*sizeof(int));
	}
	return 0;
}
