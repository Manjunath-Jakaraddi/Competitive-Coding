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
vector<vii> edges;
vi dist;
int N,M,x,y,wt,s;
void dijkstra(int s)
{
  multiset<pair<ll,int>> pq;
  dist[s]=0;
  pq.insert({0,s});
  while(!pq.empty())
  {
    pair<ll,int> z=*pq.begin();pq.erase(pq.begin());
    int frm=z.second;
    ll wei=z.first;
    if(dist[frm]<wei) continue;
    for(auto it:edges[frm])
    {
      int to=it.second,wt=it.first;
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
  cin>>N>>M;
  edges.assign(N,vii());
  dist.assign(N,INT_MAX);
  loop(i,M)
  {
    cin>>x>>y>>wt;
    x--;y--;
    edges[x].pb({wt,y});
    edges[y].pb({wt,x});
  }
  cin>>s;
  dijkstra(s-1);
  loop(i,N) cout<<dist[i]<<" ";
	return 0;
}
