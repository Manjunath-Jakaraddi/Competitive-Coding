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
// Can solve upto n=16(approx) without TLE
int dist[20][20];
int n;
int dp[1<<20][20];
int tsp(int c_mask,int pos)
{
  if(c_mask==((1<<n)-1))  return dist[pos][0];
  if(dp[c_mask][pos]) return dp[c_mask][pos];
  int ans=INT_MAX;
  loop(i,n)
  {
    if((1<<i)&c_mask) continue;
    ans=min(ans,dist[pos][i]+tsp(c_mask|(1<<i),i));
  }
  return (dp[c_mask][pos]=ans);
}
int main()
{
	prep();
  cin>>n;
  loop(i,n) loop(j,n) cin>>dist[i][j];
  cout<<tsp(1,0)<<"\n";
	return 0;
}
