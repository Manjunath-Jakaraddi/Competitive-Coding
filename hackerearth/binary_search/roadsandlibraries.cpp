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
ll q,n,m,x,y,crd,clib,num_nodes;
vector<vi> edges;
vi vis;
void dfs(int s)
{
  vis[s]=1;
  num_nodes++;
  for(auto it:edges[s]) if(!vis[it])  dfs(it);
}
void solve()
{
  cin>>n>>m>>clib>>crd;
  edges.assign(n,vi());
  vis.assign(n,0);
  loop(i,m)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
    edges[y].pb(x);
  }
  ll res=0;
  loop(i,n) if(!vis[i])
  {
    num_nodes=0;
    dfs(i);
    res+=min(num_nodes*clib,(num_nodes-1)*crd+clib);
  }
  cout<<res<<"\n";
  edges.clear();
  vis.clear();
}
int main()
{
	prep();
  cin>>q;
  while(q--)  solve();
	return 0;
}
