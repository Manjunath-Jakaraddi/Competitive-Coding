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
vi color;
vector<vi> edges;
bool isbipartite(int s,int c)
{
	color[s]=c;
  for(auto it:edges[s])
		if(color[it]==-1&&!isbipartite(it,1-c))	return false;
		else if(color[it]==c)	return false;
	return true;
}
int main()
{
	prep();
  cin>>n>>m;
  color.assign(n,-1);edges.assign(n,vi());
  loop(i,m)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
    edges[y].pb(x);
  }
  if(isbipartite(0,0))
    cout<<"IS BIPARTITE\n";
  else
    cout<<"NOT BIPARTITE\n";
  return 0;
}
