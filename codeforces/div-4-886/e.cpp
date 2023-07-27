#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
#include<cmath>
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
    int n;
    unsigned long long c;
    cin>>n;
    cin>>c;
    vector<unsigned long long> A(n);
    loop(i, n)  cin>>A[i];
    unsigned long long l=1, r=(int)sqrt(c)+1;
    while (l < r) {
        unsigned long long m = (l + ((r-l)>>1));
        unsigned long long nc = 0;
        loop(i, n)  {
            nc += ((A[i] + 2LL*m) * (A[i] + 2LL*m));
            if (nc > c) break;
        }
        if (nc >= c)    r=m;
        else l=m+1;
        // debug(l, m, r);
    }
    cout<<l<<"\n";
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
