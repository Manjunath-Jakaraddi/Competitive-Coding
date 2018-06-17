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
int n,k;
int coins[100],dp[1000];
int main()
{
	prep();
  cin>>n>>k;
  loop(i,k) cin>>coins[i];
  fill(dp,dp+1000,INT_MAX);
  dp[0]=0;
  for(int i=1;i<=11;i++)
		for(int j=0;j<k;j++ )
			if(i-coins[j]>=0)
        dp[i]=min(dp[i],1+dp[i-coins[j]]);
  cout<<dp[n]<<"\n";
  return 0;
}
