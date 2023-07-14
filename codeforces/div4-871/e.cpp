#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>

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
#define oo 1e5+5
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int gcd(int a, int b) {
   return b ? gcd(b, a % b) : a;
}

int dfs(int cx, int cy, vector<vi>& g, int n, int m) {
    int ans=g[cx][cy];
    g[cx][cy]=0;
    auto isvalid = [&](int x, int y) {
        return (x>=0&&x<n&&y>=0&&y<m&&g[x][y]!=0);
    };
    loop(d, 4) {
        int nx=cx+dx[d], ny=cy+dy[d];
        if (isvalid(nx, ny))    ans+=dfs(nx, ny, g, n, m);
    }
    return ans;
}
void solve() {
    int n, m;
    cin>>n>>m;
    vector<vi> g(n, vi(m, 0));
    loop(i, n) loop(j, m)   cin>>g[i][j];
    int ans=0;
    loop(i, n) loop(j, m) if (g[i][j] != 0)
        ans = max(ans, dfs(i, j, g, n, m));
    cout<<ans<<"\n";
}

int main()
{
    prep();
    int tt;
    cin>>tt;
    while(tt--) {
        solve();
    }
    return 0;
}
