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
int n,m,x,y,q,z,clks;
vi vis,par,disc,lowlink;
map<ii,int> bridges;
vii eprs;
vector<vi> edges;
void solve(int s)
{
  clks++;
  vis[s]=1;
  disc[s]=lowlink[s]=clks;
  int child=0;
  for(auto it:edges[s])
  {
    if(!vis[it])
    {
      child++;
      par[it]=s;
      solve(it);
      lowlink[s]=min(lowlink[s],lowlink[it]);
      if(disc[s]<lowlink[it])
        bridges[{s,it}]=1;
    }
    else if(par[s]!=it)
      lowlink[s]=min(lowlink[s],disc[it]);
  }
}
int main()
{
	prep();
  cin>>n>>m;
  edges.assign(n,vi());
  vis.assign(n,0);
  par.assign(n,-1);
  disc.assign(n,0);
  lowlink.assign(n,0);
  loop(i,m)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
    edges[y].pb(x);
    eprs.pb({x,y});
  }
  loop(i,n) if(!vis[i]) solve(i);
  cin>>q;
  while(q--)
  {
    cin>>z;
    z--;
    x=eprs[z].first,y=eprs[z].second;
    if(bridges[{x,y}]||bridges[{y,x}])  cout<<"Unhappy\n";
    else  cout<<"Happy\n";
  }
	return 0;
}
