#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
#include<cstring>
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

int a, b, d, k;
vi get_num(int n) {
    vi N;
    while(n) {
        N.pb(n%10);
        n/=10;
    }
    reverse(all(N));
    return N;
}
void solve() {
    cin>>a>>b>>d>>k;
    vi A = get_num(a), B = get_num(b);
    int dp[12][12][2];
    memset(dp, 0, sizeof dp);
    int n = B.size();
    for (int i=0; i<=B[0]; i++) {
        dp[0][1][i==B[0]] = 1;
    }
    for (int pos=1; pos<n; pos++) {
        for (int cnt=1; cnt<=k; cnt++) {
            for (bool tight : {true, false}) {
                int LMT = (tight ? B[pos] : 9);
                for (int dd=0; dd<=LMT; dd++) {
                    if (dd == d) {
                        dp[pos][cnt][tight] += dp[pos-1][cnt-1][1];
                        if (!tight) dp[pos][cnt][tight] += (dp[pos-1][cnt-1][0]);
                    } else {
                        dp[pos][cnt][tight] += dp[pos-1][cnt][1];
                        if (!tight && d<LMT) dp[pos][cnt][tight] += dp[pos-1][cnt][0];
                    }
                }
                debug(pos, cnt, tight, dp[pos][cnt][tight]);
            }
        }
    }
    int ans = dp[n-1][k][true] + dp[n-1][k][false];
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
