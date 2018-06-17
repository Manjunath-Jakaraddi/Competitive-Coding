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
int n,sm;
int val[1000];
bool dp[1000];
int main()
{
	prep();
  cin>>n>>sm;
  loop(i,n) cin>>val[i];
  dp[0]=true;
  for(int i=0;i<n;i++)
    for(int j=sm;j>=0;j--)
      if(dp[j]&&j+val[i]<=sm)
        dp[j+val[i]]=true;
  if(dp[sm]) cout<<"YES\n";
  else  cout<<"NO\n";
  return 0;
}
