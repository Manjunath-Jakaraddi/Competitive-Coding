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

void solve() {
    int n, k;
    cin>>n>>k;
    vii a(n);
    vi b(n);
    loop(i, n) {
        cin>>a[i].first;
        a[i].second = i;
    }
    loop(i, n) cin>>b[i];
    sort(all(a));
    sort(all(b));
    vi ans(n);
    loop(i, n) {
        ans[a[i].second] = b[i];
    }
    loop(i, n)  cout<<ans[i]<<" ";  cout<<"\n";
}
void querysolve() {
    int tt;
    cin>>tt;
    while(tt--) {
        solve();
    }
}
int main()
{
    prep();
    querysolve();
    // solve();
    return 0;
}
