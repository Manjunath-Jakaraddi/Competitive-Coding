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
int editdist[100][100];
int main()
{
	prep();
  cin>>s1>>s2;
  int n=s1.length(),m=s2.length();
  loop(i,n+1)  editdist[0][i]=i;
  loop(i,m+1)  editdist[i][0]=i;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(s1[i-1]==s2[j-1])  editdist[i][j]=editdist[i-1][j-1];
      else
      {
        int add=editdist[i][j-1];
        int del=editdist[i-1][j];
        int tran=editdist[i-1][j-1];
        editdist[i][j]=1+min(add,min(del,tran));
      }
    }
  }
  loop(i,n) loop(j,m) cout<<editdist[i][j]<<(j==m-1?"\n":" ");
  cout<<editdist[n-1][m-1]<<"\n";
	return 0;
}
