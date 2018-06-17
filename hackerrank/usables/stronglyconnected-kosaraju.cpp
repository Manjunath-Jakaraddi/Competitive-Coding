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
int n,m,x,y,numscc;
vi vis;
vector<vi> edges,edgest,scc;
stack<int> st;
void dfs(int s)
{
  vis[s]=1;
  for(auto it:edges[s]) if(!vis[it])  dfs(it);
  st.push(s);
}
void dfst(int s)
{
  vis[s]=1;
  for(auto it:edgest[s])  if(!vis[it])  dfst(it);
  scc[numscc].pb(s);
}
int main()
{
	prep();
  cin>>n>>m;
  vis.assign(n,0);edges.assign(n,vi());edgest.assign(n,vi());
  loop(i,m)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
    edgest[y].pb(x);
  }
  loop(i,n) if(!vis[i]) dfs(i);
  vis.clear();vis.assign(n,0);
  while(!st.empty())
  {
    int s=st.top();st.pop();
    if(vis[s]) continue;
    scc.pb(vi());
    dfst(s);
    numscc++;
  }
  int res=0;
  loop(i,scc.size())  if(scc[i].size()&1) res+=scc[i].size();
                      else  res-=scc[i].size();
  cout<<res<<"\n";
	return 0;
}
