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

int solve2(string dig, int k) {
    int n = dig.length();
    int dp[11][91][91][2];
    memset(dp, 0, sizeof dp);
    dp[0][0][0][1] = 1;
    if (k > 90) return 0;
    for (int pos=0; pos<n; pos++) {
        for (int sk=0; sk<9*n; sk++) {
            for (int kk=0; kk<9*n; kk++) {
                for (int tight : {1, 0}) {
                    int curr = dp[pos][sk][kk][tight];
                    int LMT = (tight ? dig[pos]-'0' : 9);
                    for (int dd=0; dd<=LMT; dd++) {
                        int ntight = (tight && dd == LMT);
                        int nsk = (sk + dd)%k;
                        int nk = (kk*10 + dd)%k;
                        int& next = dp[pos+1][nsk][nk][ntight];
                        next = (next + curr); 
                    }
                }
            }
        }
    }
    return (dp[n][0][0][1] + dp[n][0][0][0]);
}
int dp[11][91][91][2];
int dfs(int pos, int sm, int num, int tight, string dig, int k) {
    if (k > 90) return 0;
    int n = dig.length();
    if (pos == n) {
        return (!sm && !num);
    }
    int &curr=dp[pos][sm][num][tight];
    if (curr != -1) return curr;
    curr=0;
    int LMT = (tight ? dig[pos]-'0' : 9);
    for (int dd=0; dd<=LMT; dd++) {
        curr += dfs(pos+1, (sm+dd)%k, (num*10+dd)%k, (tight && dd==LMT), dig, k);
    }
    return curr;
}
int solve1(string dig, int k) {
    memset(dp, -1, sizeof dp);
    return dfs(0, 0, 0, 1, dig, k);
}
void solve() {
    int a, b, k;
    cin>>a>>b>>k;
    a--;
    cout<<solve1(to_string(b), k) - solve1(to_string(a), k)<<"\n"; 
}

void querysolve() {
    int tt;
    cin>>tt;
    rep(t, 1, tt) {
        cout<<"Case " << t<<": ";
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
