#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define MOD 1000000007
#define pb push_back
#define pf prllf
#define sf scanf
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(auto i=s; i<=e; i++)
#define loop(i, n) for(ll i=0; i<n; i++)
#define oo 987654321
ll dx[8]={-1,1,0,0,-1,-1,1,1};
ll dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
ll highestOneBitSet(ll x)
{
  x|=x>>1;
  x|=x>>2;
  x|=x>>4;
  x|=x>>8;
  x|x>>16;
  return (x+1)>>1;
}
ll N,D,x,y,wt;
vector<vii> tree,edges;//wt ind
vector<vi> par;
vector<ll> depth,dist_root,dist;
void bfs(ll s)
{
  queue<ll> q;
  q.push(s); // ind wt
  depth[s]=0;
  while(!q.empty())
  {
    ll z=q.front();q.pop();
    for(auto it:tree[z])  if(depth[it.second]>depth[z]+1)
    {
      par[0][it.second]=z;
      depth[it.second]=depth[z]+1;
      dist_root[it.second]=dist_root[z]+it.first;
      q.push(it.second);
    }
  }
}
ll walk(ll i,ll k)
{
  for(ll d=0;d<=D&&i!=-1;d++)  if(((1<<d)&k)>0)  i=par[d][i];
  return i;
}
ll lca(ll i,ll j)
{
  if(depth[i]>depth[j])
    i=walk(i,depth[i]-depth[j]);
  if(depth[j]>depth[i])
    j=walk(j,depth[j]-depth[i]);
  if(i==j)  return i;
  for(ll d=D;d>=0;d--)
  {
    if(par[d][i]!=par[d][j])
    {
      i=par[d][i];
      j=par[d][j];
    }
  }
  return par[0][i];
}
void dijkstra(ll s)
{
  multiset<pair<ll,int> > pq;
  dist[s]=0;
  pq.insert({0,s});
  while(!pq.empty())
  {
    ii z=*pq.begin();pq.erase(pq.begin());
    ll frm=z.second,wei=z.first;
    if(wei>dist[frm]) continue;
    for(auto it:edges[frm])
    {
      ll to=it.second,wt=it.first;
      if(dist[to]>dist[frm]+wt)
      {
        dist[to]=dist[frm]+wt;
        pq.insert({dist[to],to});
      }
    }
  }
}
int main()
{
	prep();
  cin>>N;
  tree.assign(N,vii());
  edges.assign(N,vii());
  loop(i,N-1)
  {
    cin>>x>>y>>wt;
    x--;y--;
    tree[x].pb({wt,y});
    tree[y].pb({wt,x});
  }
  D=log2(highestOneBitSet(N));
  par.assign(D+1,vi(N,-1));
  dist_root.assign(N,0);
  dist.assign(N,LLONG_MAX);
  depth.assign(N,LLONG_MAX);
  bfs(0);
  // loop(i,N+1) cout<<depth[i]<<" ";  cout<<"\n";
  // loop(i,N+1) cout<<dist_root[i]<<" ";  cout<<"\n";
  // loop(i,N+1) cout<<par[0][i]<<" ";  cout<<"\n";
  for(ll d=1;d<=D;d++)
  {
    for(ll i=0;i<N;i++)
    {
      ll mid=par[d-1][i];
      if(mid!=-1) par[d][i]=par[d-1][mid];
    }
  }
  dist[0]=0;
  for(ll i=0;i<N-1;i++)
    for(ll j=i+1;j<N;j++)
      dist[j]=min(dist[j],dist[i]+dist_root[i]+dist_root[j]-2*dist_root[lca(i,j)]);
      // edges[i].pb({dist_root[i]+dist_root[j]-2*dist_root[lca(i,j)],j});
      // cout<<i+1<<" "<<j+1<<" "<<dist_root[i]+dist_root[j]-2*dist_root[lca(i,j)]<<"\n";
  // dijkstra(0);
  loop(i,N) cout<<dist[i]<<" ";
  return 0;
}
