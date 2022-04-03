#include<bits/stdc++.h>
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
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int n, m;
vector<vi> graph;
vi par;
vi depth;
vi Tin;
vi Tout;
int T;
void dfs(int cur, int currpar=-1, int currdepth=0) {
  par[cur] = currpar;
  depth[cur] = currdepth;
  Tin[cur] = T++;
  for(auto it : graph[cur]) {
    if(it == currpar) continue;
    dfs(it, cur, currdepth+1);
  }
  Tout[cur] = T++;
}

bool isAnc(int x, int y) {
  return (Tin[x] <= Tin[y] && Tout[x] >= Tout[y]);
}
int main()
{
	prep();
  cin>>n>>m;
  graph = vector<vi>(n);
  par = depth = Tin = Tout = vi(n);
  int x, y;
  loop(i, n-1) {
    cin>>x>>y;
    x--;y--;
    graph[x].pb(y);
    graph[y].pb(x);
  }
  dfs(0);
  loop(i, m) {
    int t, maxdepthnode=0;
    cin>>t;
    vi node(t);
    loop(j, t) {
      cin>>node[j];
      node[j]--;
      if(depth[maxdepthnode] < depth[node[j]]) {
        maxdepthnode = node[j];
      }
    }
    for(auto &it: node)
      if(par[it] != -1) it=par[it];
    bool ok = true;
    for(auto it : node) {
      ok&=isAnc(it, maxdepthnode);
    }
    cout<<(ok ? "YES" : "NO")<<"\n";
  }
	return 0;
}
