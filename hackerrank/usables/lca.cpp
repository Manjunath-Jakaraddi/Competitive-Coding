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
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int x,y,D,N;
vector<vi> edges;
vi depth;
vector<vi> par;
int highestOneBitSet(int x)
{
  x|=x>>1;
  x|=x>>2;
  x|=x>>4;
  x|=x>>8;
  x|=x>>16;
  return (x+1)>>1;
}
void bfs(int s)
{
  queue<int> q;
  q.push(s);
  depth[s]=0;
  while(!q.empty())
  {
    int x=q.front();q.pop();
    for(auto it:edges[x]) if(depth[it]>depth[x]+1)
    {
      q.push(it);
      par[0][it]=x;
      depth[it]=depth[x]+1;
    }
  }
}
int walk(int i,int k)
{
  for(int d=0;d<=D&&i!=-1;d++)
    if(((1<<d)&k)>0)
      i=par[d][i];
  return i;
}
int lca(int i,int j)
{
  if(depth[i]>depth[j])
    i=walk(i,depth[i]-depth[j]);
  if(depth[j]>depth[i])
    j=walk(j,depth[j]-depth[i]);
  if(i==j)  return i;
  for(int d=D;d>=0;d--)
  {
    if(par[d][i]!=par[d][j])
    {
      i=par[d][i];
      j=par[d][j];
    }
  }
  return par[0][i];
}
int dist(int i,int j)
{
  return depth[i]+depth[j]-2*depth[lca(i,j)]+1;
}
int main()
{
	prep();
  cin>>N;
  edges.assign(N,vi());
  depth.assign(N,INT_MAX);
  rep(i,1,N-1)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
    edges[y].pb(x);
  }
  D=log2(highestOneBitSet(N));
  par.assign(D+1,vi(N,-1));
  bfs(0);
  for(int d=1;d<=D;d++)
  {
    for(int i=0;i<N;i++)
    {
      int mid=par[d-1][i];
      if(mid!=-1)
        par[d][i]=par[d-1][mid];
    }
  }
  ll sm=0;
  for(int i=1;i<=N;i++)
    for(int j=i+i;j<=N;j+=i)
      sm+=dist(i-1,j-1);
  cout<<sm<<"\n";
  return 0;
}
