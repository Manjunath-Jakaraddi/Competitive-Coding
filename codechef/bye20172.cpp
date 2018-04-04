#include<bits/stdc++.h>
using namespace std;
char board[55][55];
int n,m,sx,sy,dx,dy,cnt;
string s;
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
bool valid(int x,int y)
{
	return (x>-1&&x<m&&y>-1&&y<n&&board[x][y]!='#');
}
int solve(int sx,int sy,int dp)
{
	int tx=sx+dir[s[dp]-'0'][0];
	int ty=sy+dir[s[dp]-'0'][1];
	if(dp==s.length())	return 0;
	if(sx==dx&&sy==dy)	return 1;
	else if(valid(tx,ty))	return solve(tx,ty,dp+1);
	return 0;
}
void swapdir(int l,int r)
{
	int t1=dir[l][0],t2=dir[l][1];
	dir[l][0]=dir[r][0],dir[l][1]=dir[r][1];
	dir[r][0]=t1,dir[r][1]=t2;
}
void permute(int l, int r)
{
   int i;
   if (l == r)
  {
		if(solve(sx,sy,0))	cnt++;
	}
   else
   {
       for (i = l; i <= r; i++)
       {
          swapdir(l,i);
          permute(l+1, r);
          swapdir(l,i); //backtrack
       }
   }
}
int main()
{
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>board[i][j];
			if(board[i][j]=='S')	sx=i,sy=j,board[i][j]='.';
			if(board[i][j]=='E')	dx=i,dy=j,board[i][j]='.';
		}
	}
	cin>>s;
	permute(0,3);
	cout<<cnt;
	return 0;
}
