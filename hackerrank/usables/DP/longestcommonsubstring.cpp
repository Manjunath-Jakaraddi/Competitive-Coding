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
int n,m;
string s1,s2;
//   L C L C
// C 0 1 0 1
// L 1 0 2 0
// C 0 2 0 3
// L 1 0 3 0
// add prev diagonal if matched else put zero no taking max as it leads to subsequence
// instead take max of the matching elements
void bup()
{
  int lcs[n+1][m+1],res=0;
  memset(lcs,0,sizeof(lcs));
  vector<string> ans;
  string ts1=" "+s1,ts2=" "+s2;//temp string of 1-indexed
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(ts1[i]==ts2[j])
      {
        lcs[i][j]=1+lcs[i-1][j-1];
        if(lcs[i][j]>=res)
        {
          if(lcs[i][j]==res)
            // Same length different strings just add them
            ans.pb(ts1.substr(j-lcs[i][j]+1,lcs[i][j]));
          else
          {
            // new max length erase all prev string of smaller length and insert new one
            ans.clear();
            ans.pb(ts1.substr(j-lcs[i][j]+1,lcs[i][j]));
          }
          res=max(lcs[i][j],res);
        }
      }
      else  lcs[i][j]=0; //Not reqd as initally set to zero
    }
  }
  cout<<"Length of the max Common Substring : "<<res<<"\n";
  for(auto it:ans)  cout<<it<<"\n";
}
int main()
{
	prep();
  cin>>s1>>s2;
  n=s1.length();m=s2.length();
  bup();
	return 0;
}
