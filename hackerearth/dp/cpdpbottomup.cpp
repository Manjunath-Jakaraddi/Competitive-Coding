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
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int m,c,t;
int models[22][22];
int size[22];
bool dp[22][222];
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    cin>>m>>c;
    loop(i,c)
    {
      cin>>size[i];
      loop(j,size[i]) cin>>models[i][j];
    }
    memset(dp,false,sizeof dp);
    for(int i=0;i<size[0];i++)  dp[0][m-models[0][i]]=true;
    for(int i=1;i<c;i++)
      for(int j=m;j>=0;j--)
        if(dp[i-1][j])
          for(int k=0;k<size[i];k++)
            if(j-models[i][k]>=0) dp[i][j-models[i][k]]=true;
    bool ok=false;
    rep(i,0,m)
      if(dp[c-1][i])
      {
        ok=true;
        cout<<m-i<<"\n";
        break;
      }
    if(!ok) cout<<"no solution\n";
  }
	return 0;
}
