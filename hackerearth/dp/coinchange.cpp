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
int coins[55],dp[300];
int main()
{
	prep();
  cin>>n>>k;
  loop(i,k) cin>>coins[i];
  dp[0]=1;
  for(int i=0;i<k;i++)
    for(int j=0;j<=n;j++)
      dp[j+coins[i]]+=dp[j];
  // loop(i,10)  cout<<dp[i]<<" ";
  cout<<dp[n]<<"\n";
  return 0;
}
