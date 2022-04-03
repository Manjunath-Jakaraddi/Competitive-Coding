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
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
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
vii adj[11];
int n, m;
int x, y, c;
int dp[11][(1<<10)+5];
map<ii, int> mmap;
int main()
{
	prep();
	cin>>n>>m;
	loop(i,m) {
		cin>>x;
		cin>>y;
		cin>>c;
		x--;y--;
		mmap[{x,y}]=c;
		mmap[{y,x}]=c;
	}

	for(int mask=1; mask<(1<<n); mask++) {
		for(int i=0; i<n; i++) {
			if(mask&(1<<i)) {
				for(int j=0; j<n; j++) {
					if(i!=j &&  && mmap[{i,j}]!=0) {
						dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask] + mmap[{i,j}]);
					}
				}
			}
		}
	}
	for(int mask=0;mask<(1<<n); mask++) if(dp[mask]==INT_MAX) cout<<"-1 "; else cout<<dp[mask]<<" ";
	cout<<"\n";
	cout<<dp[(1<<n)-1]<<"\n";
	return 0;
}
