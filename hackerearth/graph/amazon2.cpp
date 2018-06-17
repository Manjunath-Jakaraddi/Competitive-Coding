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
int t,n;
int dp[100005][3];
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    cin>>n;
    loop(i,n) cin>>dp[i][0]>>dp[i][1]>>dp[i][2];
    for(int i=1;i<n;i++)
    {
      dp[i][0]+=min(dp[i-1][1],dp[i-1][2]);
      dp[i][1]+=min(dp[i-1][0],dp[i-1][2]);
      dp[i][2]+=min(dp[i-1][0],dp[i-1][1]);
    }
    cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]))<<"\n";
  }
  return 0;
}
