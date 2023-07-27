#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
#include<set>
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

ll n;
bool isPermutation(vector<ll>& A) {
    loop(i, n) if (A[i]<=0 || A[i]>n)  return false;
    set<ll> s(all(A));
    return s.size() == n;
}

vector<ll> prefSumToArray(vector<ll> p) {
    vector<ll> res(n);
    res[0]=p[0];
    rep(i, 1, n-1) res[i]=p[i]-p[i-1];
    return res;
}


void solve() {
    cin>>n;
    vector<ll> A(n-1);
    loop(i, n-1)    cin>>A[i];
    ll x=(n*(n+1))/2;
    if (A.back() != x) {
        A.pb(x);
        vector<ll> b = prefSumToArray(A);
        if (isPermutation(b))   cout<<"YES\n";
        else cout<<"NO\n";
        return;
    }
    map<ll, int> cnt;
    cnt[A[0]]++;
    rep(i, 1, n-2)  cnt[A[i]-A[i-1]]++;
    vi cntGt1;
    for(auto& [k, v] : cnt) {
        if (v > 1)  cntGt1.pb(k);
    }
    if (cntGt1.size() > 1) {
        cout<<"NO\n";
        return;
    }
    if (cntGt1.size() == 1 && cnt[cntGt1[0]] > 2) {
        cout<<"NO\n";
        return;
    }
    vi cnt0;
    rep(i, 1, n) {
        if(cnt[i]==0)   cnt0.pb(i);
    }
    if (cnt0.size() != 2) {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
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
