#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
long long dp[2002][2002];
int main()
{
  int k,n;
	cin>>n>>k;
	for(int i=0;i<=n;i++)	dp[0][i]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int l=j;l<=n;l+=j)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][l])%1000000007;
			}
		}
	}
	cout<<dp[k][1];
  return 0;
}
