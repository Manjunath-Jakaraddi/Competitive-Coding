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
vi indeg,vis,tsort;
set<int> q;//To print the lexicographically smallest topological sort
void bfs()
{
  while(!q.empty())
  {
    int z=*q.begin();q.erase(q.begin());
    tsort.pb(z);
    for(auto it:edges[z])
    {
      if(!vis[it])
      {
        indeg[it]--;
        if(!indeg[it])
        {
          vis[it]=1;
          q.insert(it);
        }
      }
    }
  }
}
int main()
{
	prep();
	cin>>n>>m;
	vis.assign(n,0);indeg.assign(n,0);edges.assign(n,vi());
	loop(i,m)
	{
	    cin>>x>>y;
	    x--;y--;
	    edges[x].pb(y);
	    indeg[y]++;
	}
  loop(i,n) sort(all(edges[i]));
	loop(i,n)   if(!indeg[i])
  {
    vis[i]=1;
    q.insert(i);
  }
  bfs();
	for(auto it:tsort)  cout<<it+1<<" ";
	return 0;
}
