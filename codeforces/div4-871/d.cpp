#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>

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
    int n,t;
    cin>>n>>t;
    int g = gcd(n, t);
    n/=g;
    t/=g;
    if (n == t) {
        cout<<"Yes\n";
        return;
    }
    int cntn=0, cntt=0;
    while((n%3)==0) {
        cntn++;
        n/=3;
    }
    while((t%3)==0) {
        cntt++;
        t/=3;
    }
    while((t%2)==0) {
        cntt++;
        t/=2;
    }
    if (cntn < 1 || t!=1 || n!= 1 || (cntn <  cntt)) {
        cout<<"No\n";
    } else cout<<"Yes\n";
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
