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
ll n,k,m,x,y,wt;
vector<vector<pair<ll,int> > > edges;
vector<ll> dist;
ll getwaittime(ll x)
{
  ll z=x/k;
  if(z&1) return k-(x%k);
  return 0LL;
}
void dijkstra(int s)
{
  multiset<pair<ll,int> > pq;
  pq.insert({0,s});
  dist[s]=0;
  while(!pq.empty())
  {
    ii z=*pq.begin();pq.erase(pq.begin());
    int frm=z.second;
    ll wei=z.first;
    if(dist[frm]>wei) continue;
    for(auto it:edges[frm])
    {
      int to=it.second;
      ll wt=it.first;
      ll wait=getwaittime(dist[frm]);
      if(dist[to]>dist[frm]+wt+wait)
      {
        // cout<<to+1<<" "<<wait<<"@\n";
        dist[to]=dist[frm]+wt+wait;
        pq.insert({dist[to],to});
      }
    }
  }
}
int main()
{
	prep();
  cin>>n>>k>>m;
  edges.assign(n,vector<pair<ll,int> >());
  dist.assign(n,LLONG_MAX);
  loop(i,m)
  {
    cin>>x>>y>>wt;
    x--;y--;
    edges[x].pb({wt,y});
    edges[y].pb({wt,x});
  }
  dijkstra(0);
  cout<<dist[n-1]<<"\n";
	return 0;
}
