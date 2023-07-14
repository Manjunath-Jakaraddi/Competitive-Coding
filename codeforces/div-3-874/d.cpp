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
#define rrep(i, s, e) for(auto i=s; i>=e; i--)
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
    int n;
    cin>>n;
    vi p(n);
    loop(i, n)  cin>>p[i];
    int mxInd=-1, mx=0;
    rep(i, 1, n-1) {
        if (p[i] > mx) {
            mx=p[i];
            mxInd=i;
        }
    }
    if (mxInd == -1) {
        cout<<p[0]<<"\n";
        return;
    }
    int r=(mxInd == n-1 ? mxInd : mxInd-1);
    rep(i, mxInd, n-1)  cout<<p[i]<<" ";
    if (mxInd != n-1) cout<<p[r]<<" ";
    rrep(i, r-1, 0) {
        if (p[i] > p[0]) {
            cout<<p[i]<<" ";
        } else {
            rep(j, 0, i) {
                cout<<p[j]<<" ";
            }
            break;
        }
    }
    cout<<"\n";
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
