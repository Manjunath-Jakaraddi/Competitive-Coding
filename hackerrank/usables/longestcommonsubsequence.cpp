#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define pb push_back
#define pf printf
#define sf scanf
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(auto i=s; i<=e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
string s1,s2;
int n,m;
int lcs[100][100],way[100][100];
// 		LCS						PTR  1->diag(s1/s2) 2->(s1) up  3->(s2) left
// 	(s2)A C B	E	A
// 		A 1 1 1 1 1
// 		D 1 1 1 1 1
// (s1)C 1 2 2 2 2
// 		A 1 2 2 2 3
void displaymatrix()
{
	rep(i,1,n)
		rep(j,1,m)
			cout<<lcs[i][j]<<(j==m?"\n":" ");
	rep(i,1,n)
		rep(j,1,m)
			cout<<way[i][j]<<(j==m?"\n":" ");
}
string getsubsequence()
{
	string subsequence="";
	int i=n,j=m;
	while(i>=0&&j>=0)
	{
		if(way[i][j]==1)
		{
			subsequence.pb(s1[i-1]);
			i--;
			j--;
		}
		else if(way[i][j]==2)	i--;
		else	j--;
	}
	reverse(all(subsequence));
	return subsequence;
}
void bup()
{
	string ts1=" "+s1,ts2=" "+s2;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ts1[i]==ts2[j])
			{
				lcs[i][j]=1+lcs[i-1][j-1];//considering diag element
				way[i][j]=1;// move diag left up when encountered with 1
			}
			else
			{
				int consider_prev_row=lcs[i-1][j],//considering prev row element
				consider_prev_col=lcs[i][j-1];//considering prev col element
				if(consider_prev_row>=consider_prev_col)
				{
					// when row col equal choose randomly row many possible ans might exists
					lcs[i][j]=consider_prev_row;
					way[i][j]=2;// move up when encountered with 2
				}
				else
				{
					lcs[i][j]=consider_prev_col;
					way[i][j]=3; //move left when encountered with 3
				}
			}
		}
	}
	// displaymatrix();
	cout<<"Longest Common subsequence is "<<getsubsequence()<<" of length "<<lcs[n][m]<<"\n";
}
int solve(int i,int j)
{
	if(i>=n||j>=m)	return 0;
	if(s1[i]==s2[j])	return 1+solve(i+1,j+1);
	return max(solve(i+1,j),solve(i,j+1));
}
int main()
{
	prep();
  cin>>s1>>s2;
	n=s1.length();
	m=s2.length();
	bup();
	cout<<solve(0,0)<<"\n";
  return 0;
}
