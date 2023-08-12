#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

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
#define rrep(i, s, e) for(auto i=s; i>=e; i--)
#define loop(i, n) for(int i=0; i<n; i++)
#define oo 1e9+5
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
    int n, x;
    cin>>n>>x;
    vi h(n), s(n);
    loop(i, n)  cin>>h[i];
    loop(i, n)  cin>>s[i];
    vi dp(x+1, -1);
    dp[0]=0;
    int ans = 0;
    for (int b=0; b<n; b++) {
        for (int i=x; i>=0; i--) {
            if (dp[i] != -1 && i+h[b] <= x) {
                dp[i+h[b]] = max(dp[i] + s[b], dp[i+h[b]]);
                ans = max(ans, dp[i+h[b]]);
            }
        }
    }
    cout<<ans<<"\n";
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
    // querysolve();
    solve();
    return 0;
}
