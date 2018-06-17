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
int n,m,x,y,clks;
vector<vi> edges(10);
vi ap,disc,lowlink,vis,par;
vii bridges;
// ap: articulation point disc : time of discovery of node
// lowlink : lowest time neighbour to given node par : par of node
void findAP(int s)
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
      findAP(it);
      lowlink[s]=min(lowlink[it],lowlink[s]);//Back Propagatate the updates
      if(disc[s]<lowlink[it]) bridges.pb({s,it}); //Bridge if node discovered earlier than other node not equal
                                                  //No special root case for Bridges
      if(par[s]==-1&&child>1) //AP Case 1: root with two or more children(or subtress)
        ap[s]=1;
      else if(par[s]!=-1&&disc[s]<=lowlink[it]) //AP Case 2: non root node must be dicovered earlier than all the childs
        ap[s]=1;
    }
    else if(par[s]!=it)
      lowlink[s]=min(lowlink[s],disc[it]);
  }
}
int main()
{
	prep();
  vi AP;
  cin>>n>>m;
  ap.assign(n,0);vis.assign(n,0);
  disc.assign(n,0);lowlink.assign(n,0);
  par.assign(n,-1);
  loop(i,m)
  {
    cin>>x>>y;
    edges[x].pb(y);
    edges[y].pb(x);
  }
  findAP(0);
  for(int i=0;i<n;i++)  if(ap[i]) AP.pb(i);
  sort(all(bridges));
  cout<<AP.size()<<"\n";
  for(auto it:AP) cout<<it<<" ";
  cout<<"\n"<<bridges.size()<<"\n";
  for(auto it:bridges)  cout<<it.first<<" "<<it.second<<"\n";
	return 0;
}
