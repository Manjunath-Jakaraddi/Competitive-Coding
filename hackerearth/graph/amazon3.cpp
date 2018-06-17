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
#define rep(i, s, e) for(auto i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
ll dp[102][10004];
int t,n,k;
int main()
{
	prep();
  cin>>t;
  for(int i=1;i<=10000;i++) dp[1][i]=1;
  for(int i=1;i<=100;i++) dp[i][1]=1;
  for(int i=2;i<=100;i++)
  {
    for(int j=2;j<=10000;j++)
    {
      if(j<=i)  dp[i][j]+=1;
      for(int x=1;x<=i;x++)
      {
        if(j-x>0) dp[i][j]=(dp[i][j]+dp[i][j-x])%MOD;
      }
    }
  }
  while(t--)
  {
    cin>>n>>k;
    cout<<dp[k][n]<<"\n";
  }
  return 0;
}
// int dp[10004]={0};
// cin>>n>>k;
// loop(i,k) dp[i+1]=1;
// for(int i=1;i<=n;i++)
// {
//   for(int j=1;j<=k;j++)
//   {
//     if(i-j<0) break;
//     dp[i]+=dp[i-j];
//   }
// }
// cout<<dp[n]<<"\n";
