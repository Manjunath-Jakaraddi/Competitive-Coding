#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
#include<assert.h>

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

void solve() {
    int n, m, x, y;
    cin>>n>>m;
    vi in(n+1);
    loop(i, m) {
        cin>>x>>y;
        in[x]++;
        in[y]++;
    }
    unordered_map<int, int> cnt;
    rep(i, 1, n) cnt[in[i]]++;
    vi ans;
    for (auto x : cnt) {
        ans.pb(x.second);
    }
    sort(all(ans));
    if (ans.size() == 3) {
        cout << ans[0] << " " << ans[1] - 1 <<"\n";
    } else {
        cout << ans[0] << " " << ans[0] - 1 <<"\n";
    }
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
