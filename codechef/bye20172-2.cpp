#include<bits/stdc++.h>
using namespace std;
string s[55];
int m,n;
bool valid(int x,int y)
{
	return (x>-1&&x<m&&y>-1&&y<n&&s[x][y]!='#');
}
int main()
{
	int dx[]={-1,0,1,0};
	int dy[]={0,-1,0,1};
	vector<int> p{0,1,2,3};
	int sx,sy;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>s[i];
		for(int j=0;j<n;j++)	if(s[i][j]=='S')	sx=i,sy=j;
	}
	string w;
	cin>>w;
	int cnt=0;
	do
	{
		int x=sx,y=sy,tx,ty,fail=false;
		for(auto c:w)
		{
			int tx=x+dx[p[c-'0']];
			int ty=y+dy[p[c-'0']];
			if(valid(tx,ty))	x=tx,y=ty;
			else{			fail=true;break;}
			if(s[x][y]=='E')	break;
		}
		if(!fail&&s[x][y]=='E')	cnt++;	
	}while(next_permutation(p.begin(),p.end()));
	cout<<cnt<<endl;
	return 0;
}
