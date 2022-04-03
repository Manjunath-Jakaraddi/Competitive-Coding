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
string grid[11];
int t, n, m;
int dp[2][11][11][(1<<11)+5];

int solve(int h, int i, int j, int mask) {
	if(j == m) return solve(0, i+1, 0, mask);
	if(i == n) return 0;
	int &res = dp[h][i][j][mask];
	if(res!=0) {
		return res;
	}
	res = oo;
	int missingCol = (((1<<m)-1) - (1<<j)) & mask;
	if(grid[i][j] == '#') {
		res = solve(0, i, j+1, missingCol);
	} else {
		if(h) res = min(res, solve(1, i, j+1, missingCol));
		if(mask&(1<<j)) res = min(res, solve(0, i, j+1, mask));

		res = min(res, 1 + solve(1, i, j+1, missingCol));
		res = min(res, 1+ solve(0, i, j+1, mask | (1<<j)));
	}
	return res;
}
int main()
{
	prep();
  cin>>t;
  for(int k=0; k<t; k++) {
    cin>>n>>m;
		memset(dp, 0, sizeof(dp[0][0][0][0]) * 2 * 11 * 11 * ((1<<11)+5));
    loop(i, n) {
      cin>>grid[i];
    }
		// cout<<"Computing for test case : "<<k+1<<"/"<<t<<"\n";
		cout<<solve(0, 0, 0, 0)<<"\n";
  }
	return 0;
}
