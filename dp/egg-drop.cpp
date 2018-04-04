#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int eggdropr(int n,int k)
{
	int mn=INT_MAX;
	if(dp[n][k])	return dp[n][k];
	for(int i=1;i<=k;i++)
	{
		if(!dp[n-1][i-1])	dp[n-1][i-1]=eggdropr(n-1,i-1);
		if(!dp[n][k-i])		dp[n][k-i]=eggdropr(n,k-i);
		mn=min(mn,max(dp[n-1][i-1],dp[n][k-i]));
	}
	return dp[n][k]=mn+1;
}
int main()
{
	int n,k;
	for(int i=1;i<=100;i++)		dp[1][i]=i,dp[i][1]=1;
	cin>>n>>k;
	cout<<eggdropr(n,k);
	return 0;
}
