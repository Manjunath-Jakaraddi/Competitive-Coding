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
    int n, u;
    cin>>n>>u;
    vi a(n);
    loop(i, n)  cin>>a[i];
    vector<vector<int>> dp(n, vi(u+1, 0));
    if (a[0] != 0) {
        dp[0][a[0]]=1;
    } else {
        rep(i, 1, u)    dp[0][i]=1;
    }
    for (int i=1; i<n; i++) {
        if (a[i] != 0) {
            for (int num : {a[i]-1, a[i], a[i]+1}) {
                if (num < 1 || num > u) continue;
                dp[i][a[i]] = (dp[i][a[i]] + dp[i-1][num])%MOD; 
            }
        } else {
            for (int c=1; c<=u; c++) {
                for (int num : {c-1, c, c+1}) {
                    if (num < 1 || num > u) continue;
                    dp[i][c] = (dp[i][c] + dp[i-1][num])%MOD; 
                }
            }
        }
    }
    if (a[n-1] != 0) {
        cout<<dp[n-1][a[n-1]]<<"\n";
    } else {
        int ans=0;
        for (int i=1; i<=u; i++) {
            ans = (ans + dp[n-1][i]) % MOD;
        }
        cout<<ans<<"\n";
    }
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
