#include<bits/stdc++.h>
using namespace std;
long long dp[100];
void initialise()
{
	for(int i=0;i<100;i++)
		dp[i]=-1;
}
/*
long long fib(int  n)
{
	if(n<=1)
		return n;
	return fib(n-1)+fib(n-2);
}
long long fib(int  n)
{
	if(dp[n]==-1)
	{
	if(n<=1)	dp[n]=n;
	else	dp[n]=fib(n-1)+fib(n-2);
	}
	return dp[n];
}*/
long long fib(int n)
{
	long long f[n+1];
	f[0]=0;
	f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=f[i-1]+f[i-2];
	return f[n];
}
int main()
{
	int n;
	cin>>n;
	initialise();
	cout<<(1LL*fib(n))<<endl;
	for(int i=0;i<100;i++){	cout<<dp[i]<<" ";if(i%10==0)	cout<<endl;}
	return 0;
}
