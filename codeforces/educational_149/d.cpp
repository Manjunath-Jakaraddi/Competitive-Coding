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

bool check_beautiful(string s) {
    int x=0;
    for (char c: s) {
        if (c == '(')   x++;
        else x--;
        if (x<0)    return false;
    } 
    return true;
}
void solve1() {
    int n;
    string s;
    cin>>n>>s;
    vi st, u;
    int c=0;
    vi res(n);
    loop(i, n) {
        if (s[i] == ')') {
            if (!st.empty()) {
                if (!c) c++;
                res[i]=res[st.back()]=c;
                st.pop_back();
            }
            else u.push_back(i);
        } else {
            st.push_back(i);
        }
    }
    if (u.size() != st.size()) {
        pf("-1\n");
        return;
    }
    reverse(all(s));
    if (check_beautiful(s)) {
        pf("1\n");
        loop(i, n)  pf("1 ");   pf("\n");
        return;
    }
    c+=(!u.empty());
    pf("%d\n", c);
    loop(i, u.size()) {
        res[u[i]]=res[st[i]]=c;
    }
    loop(i, n)  pf("%d ", res[i]);  pf("\n");
}
void solve() {
    int n;
    string s;
    cin>>n>>s;
    int x=0, p=0;
    vi res(n);
    bool use=false;
    loop(i, n) {
        if (s[i] == '(')    x++;
        else x--;
        if (p>0 && !x) {
            use=true;
            res[i]=1;
        }
        if (x>0) {
            use=true;
            res[i]=1;
        }
        p=x;
    }
    loop(i, n) {
        if (s[i] == '(')    x++;
        else x--;
        if (!x && p<0) res[i]=(use+1);
        if (x<0)    res[i]=(use+1);
        p=x;
    }
    if (x) {
        pf("-1\n");
        return;
    }
    int ans=*max_element(all(res));
    pf("%d\n", ans);
    loop(i, n) pf("%d ", res[i]); pf("\n");
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
