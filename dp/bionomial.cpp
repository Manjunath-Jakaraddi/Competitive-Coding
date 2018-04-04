#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int b(int n,int k)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(j==0||j==i)	dp[i][j]=1;
			else		dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
		}
	}
	return dp[n][k];
}
int main()
{
	int n,k;
	cin>>n>>k;
	cout<<b(n,k);
	return 0;
}
