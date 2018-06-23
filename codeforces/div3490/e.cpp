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
int N,E,s,x,y,num_scc,dfs_counter;
vector<vi> edges,dag;
vi dfs_num,dfs_low,st,belong,indeg,vis;
void tarjan(int s)
{
  dfs_counter++;
  dfs_num[s]=dfs_low[s]=dfs_counter;
  st.pb(s);
  for(auto it:edges[s])
  {
    if(!dfs_num[it])  tarjan(it);
    dfs_low[s]=min(dfs_low[it],dfs_low[s]);
  }
  if(dfs_num[s]==dfs_low[s])
  {
    num_scc++;
    while(1)
    {
      int ele=st.back();st.pop_back();
      dfs_low[ele]=N;
      belong[ele]=num_scc;
      if(ele==s)  break;
    }
  }
}
void dfs(int s)
{
  vis[s]=1;
  for(auto it:dag[s]) if(!vis[it])  dfs(it);
}
int main()
{
	prep();
  cin>>N>>E>>s;
  edges.assign(N,vi());
  dag.assign(N,vi());
  dfs_num.assign(N,0);
  dfs_low.assign(N,0);
  belong.assign(N,0);
  indeg.assign(N+1,0);
  vis.assign(N+1,0);
  loop(i,E)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
  }
  num_scc=-1;
  loop(i,N) if(!dfs_num[i])  tarjan(i);
  loop(i,N) for(auto it:edges[i])
  {
    if(belong[i]==belong[it]) continue;
    dag[belong[i]].pb(belong[it]);
    indeg[belong[it]]++;
  }
  dfs(belong[s-1]);
  int res=0;
  loop(i,num_scc+1) res+=(!indeg[i]&&!vis[i]);
  cout<<res<<"\n";
  return 0;
}
