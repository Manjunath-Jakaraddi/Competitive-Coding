#include<bits/stdc++.h>
using namespace std;
int arr[4][2]={{0,0},{3,2},{-5,-10},{-20,5}};
int dp[1002][1002];
int solve(int x,int y,int lvl)
{
	if(x<=0||y<=0)	return 0;
	if(dp[x][y])	return dp[x][y];
	for(int i=1;i<=3;i++)
	{
		if(i==lvl)	continue;
		dp[x][y]=max(dp[x][y],1+solve(x+arr[i][0],y+arr[i][1],i));
	}
	return dp[x][y];
	/*if(lvl==1)
	{
		return dp[x][y]=1+max(solve(x-5,y-10,2),solve(x-20,y+5,3));
	}
	else if(lvl==2)
	{
		return dp[x][y]=1+max(solve(x+3,y+2,1),solve(x-20,y+5,3));
	}
	else if(lvl==3)
	{
		return dp[x][y]=1+max(solve(x+3,y+2,1),solve(x-5,y-10,2));
	}
	else
	{
		return dp[x][y]=1+max(solve(x+3,y+2,1),max(solve(x-5,y-10,2),solve(x-20,y+5,3)));
	}*/

}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y,0)-1<<endl;
		memset(dp,0,1002*1002*sizeof(int));
	}
	return 0;
}
