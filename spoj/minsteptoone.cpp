#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
long long dp[20000007];
long long solve(long long n)
{
	if(n==1)	return 0;
	if(n==2||n==3)	return 1;
	if(dp[n])	return dp[n];
	if(n%3==0)	dp[n]=1+min(solve(n-1),solve(n/3));
	else if(n%2==0)	dp[n]=1+min(solve(n-1),solve(n/2));
	else	dp[n]=1+solve(n-1);
	return dp[n];
}
int main()
{
  int t;
cin>>t;
	/*for(int i=2;i<=20000007;i++)
	{
		if(i%3==0)	dp[i]=1+dp[i/3];
		else if(i%2==0)	dp[i]=1+dp[i/2];
		else		dp[i]=1+dp[i-1];
	}*/
	int i=0;
	while(t--)
	{
		i++;
		long long n;
		cin>>n;
		cout<<"Case "<<i<<": "<<solve(n)<<endl;
	}
  return 0;
}

