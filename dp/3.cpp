#include<bits/stdc++.h>
using namespace std;
int v[1001];
int dp[1001][1001];
int maxx(int a, int b, int c, int d) {
	return(max(max(a, b), max(c, d)));
}

int solve(int l,int r)
{
	int a,b;
	if(l>r)	return 0;
	if(dp[l][r]) return dp[l][r];
	a=maxx(v[l]-v[l+1]+solve(l+2,r), v[l]-v[r]+solve(l+1,r-1), v[r]-v[r-1]+solve(l,r-2), v[r]-v[l]+solve(l+1, r-1));
	dp[l][r]=a;
	return a;
}
int main()
{
	int x,it=1,a;
	while(1)
	{
		cin>>x;
		if(x==0)	break;
		if(it!=1)	memset(dp, 0, 1001*1001*sizeof(int));
		for(int i=0;i<x;i++)	cin>>v[i];
		cout<<"In game "<<it<<", the greedy strategy might lose by as many as "<<solve(0,x-1)<<" points."<<endl;
		it++;
	}
	return 0;
}
