#include<bits/stdc++.h>
using namespace std;
int dp[10000005];
		int a,b;
		int mb=0;
				int mx=0,sm=0;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(dp,0,10000005*sizeof(int));
		mb=0,mx=0,sm=0;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			dp[a]++;
			dp[b+1]--;
			mb=max(mb,b)
		}

		for(int i=0;i<=mb;i++)
		{
			sm+=dp[i];
			mx=max(mx,sm);
		}
		cout<<mx<<endl;
	}
	return 0;
}
