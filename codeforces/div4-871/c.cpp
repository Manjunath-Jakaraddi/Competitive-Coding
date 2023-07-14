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
int bintoint(string s) {
    return ((2 * (s[0] - '0')) + (s[1] - '0'));
}
void solve() {
    int n, val;
    string s;
    cin>>n;
    vector<ll> arr(4, INT_MAX);
    loop(i, n) {
        cin>>val>>s;
        int x = bintoint(s);
        arr[x] = min(arr[x], (ll)val);
    }
    if (arr[3] == INT_MAX && (arr[1] == INT_MAX || arr[2] == INT_MAX)) {
        cout << "-1\n";
    } else cout<<min(arr[3], arr[1] + arr[2])<<"\n";
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
