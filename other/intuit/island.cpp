#include<bits/stdc++.h>
using namespace std;
int mat[100][100];
int m,n;
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
bool valid(int x,int y)
{
	return (x>-1&&x<m&&y>-1&&y<n&&mat[x][y]);
}
int dfs(int x,int y)
{
	mat[x][y]=0;
	for(int i=0;i<8;i++)
	{
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(valid(nx,ny))	dfs(nx,ny);
	}
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>mat[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(mat[i][j])
			{
				dfs(i,j);
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
