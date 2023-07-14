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

void dfs(int c, vector<vi> &adj, vi &vis, int k) {
    vis[c]=k;
    for (int n : adj[c]) 
        if (!vis[n]) dfs(n, adj, vis, k);
}
void solve() {
    int n;
    cin>>n;
    vi arr(n), vis(n, 0);
    vector<vi> adj(n, vi());
    loop(i, n)  {
        cin>>arr[i];
        arr[i]--;
        adj[i].pb(arr[i]);
        adj[arr[i]].pb(i);
    }
    int b=0, c=0;
    loop(i, n) {
        if (!vis[i]) {
            dfs(i, adj, vis, i+1);
            bool isb=false;
            loop(j, n) {
                if (vis[j] == i+1 && adj[j].size() == 1) {
                    isb=true;
                    break;
                }
            }
            (isb ? b++ : c++);
        }
    }
    cout<<c+min(b,1)<<" "<<c+b<<"\n";
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
