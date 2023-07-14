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
    // least even < least odd NO
    // ALL even or ALL odd yes
    int n, x;
    int le = INT_MAX, lo=INT_MAX, ec=0, oc=0;
    cin>>n;
    loop(i, n) {
        cin>>x;
        if (x&1) {
            // odd
            oc++;
            lo=min(lo, x);
        } else {
            ec++;
            le=min(le, x);
        }
    }
    if (oc == n || ec == n) {
        cout<<"YES\n";
    } else {
        if (le < lo) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }
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
    querysolve();
    // solve();
    return 0;
}
