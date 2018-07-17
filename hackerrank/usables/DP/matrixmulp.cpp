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
int n;
vi arr;
int dp[100][100];
int cost_matrix()
{
  for(int len=2;len<n;len++)
  {
    for(int i=0;i<n-1;i++)
    {
      int j=i+len;
      dp[i][j]=INT_MAX;
      for(int k=i+1;k<j;k++)
      {
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
      }
    }
  }
  loop(i,n) loop(j,n) cout<<dp[i][j]<<(j==n-1?"\n":" ");
  return dp[0][n-1];
}
int main()
{
	prep();
  cin>>n;
  arr.assign(n,0);
  loop(i,n) cin>>arr[i];
  cout<<cost_matrix()<<"\n";
	return 0;
}
