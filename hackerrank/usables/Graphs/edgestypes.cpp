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
int cnt=0;
#define EXPLORED 2
#define VISITED 1
#define UNVISITED 0
vi dfs_num,dfs_par;
int n,m,x,y,numcomp;
vector<vi> edges;
void dfs(int s)
{
  dfs_num[s]=EXPLORED;
  for(auto it:edges[s])
  {
    if(dfs_num[it]==UNVISITED)
    {
      //TREE EDGE EXPLORED -> UNVISITED
      dfs_par[it]=s;
      dfs(it);
    }
    else if(dfs_num[it]==EXPLORED)
    {
      //EXPLORED -> EXPLORED Two cases
      if(it==dfs_par[s])  //Two Way Edge 2 - 3 - 2 undirected graph
        cout<<"Two ways "<<s<<" "<<it<<"-"<<it<<" "<<s<<"\n";
      else //Back Edge forming cycle
      {
				cnt++;
				cout<<"Back Edge "<<s<<" "<<it<<"\n";
			}
    }
    else if(dfs_num[it]==VISITED) // EXPLORED -> VISITED
      cout<<"Cross Edge "<<s<<" "<<it<<"\n";
  }
  dfs_num[s]=VISITED; //VISITED Done complete exploration
}
int main()
{
	prep();
  cin>>n>>m;
  dfs_num.assign(n,0);dfs_par.assign(n,0);edges.assign(n,vi());
  loop(i,m)
  {
    cin>>x>>y;
    // x--;y--;
    edges[x].pb(y);
    // edges[y].pb(x);
  }
  loop(i,n) if(dfs_num[i]==UNVISITED)
  {
    cout<<"Component "<<++numcomp<<":\n";
    dfs(i);
  }
	cout<<cnt<<"\n";
	return 0;
}
