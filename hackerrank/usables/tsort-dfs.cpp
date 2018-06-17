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
int n,m,x,y;
vector<vi> edges;
vi vis;
deque<int> tsort;
void dfs(int s)
{
  vis[s]=1;
  for(auto it:edges[s]) if(!vis[it])  dfs(it);
  tsort.push_front(s);
}
int main()
{
	prep();
  cin>>n>>m;
  vis.assign(n,0);edges.assign(n,vi());
  loop(i,m)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
  }
  loop(i,edges.size())
  {
    cout<<i+1<<": ";
    for(auto it:edges[i]) cout<<it+1<<" ";
    cout<<"\n";
  }
  loop(i,n) sort(all(edges[i]));

  loop(i,edges.size())
  {
    cout<<i+1<<": ";
    for(auto it:edges[i]) cout<<it+1<<" ";
    cout<<"\n";
  }
  loop(i,n) if(!vis[i]) dfs(i);
  // reverse(all(tsort));
  while(!tsort.empty())
  {
    cout<<tsort.front()+1<<" ";
    tsort.pop_front();
  }
	return 0;
}
