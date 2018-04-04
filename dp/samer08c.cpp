#include<bits/stdc++.h>
using namespace std;
long long solve(vector<long long> &v)
{
	long long dp[100005];
	dp[0]=0;	
	dp[1]=v[1];
	for(int i=2;i<=v.size()-1;i++)	dp[i]=max(dp[i-2]+v[i],dp[i-1]);
	return dp[v.size()-1];
}
int main()
{
	while(1)
	{
		int m,n;
		cin>>m>>n;
		if(m==0||n==0)	break;
		vector<vector<long long> > v(m+1, vector<long long>(n+1));
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				cin>>v[i][j];
		vector<long long> res(m+1);
		for(int i=1;i<=m;i++)
			res[i]=solve(v[i]);
		cout<<solve(res)<<endl;
	}
	return 0;
}
