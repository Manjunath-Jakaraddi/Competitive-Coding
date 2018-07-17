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
#define rep(i, s, e) for(auto i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int vis[100005];
vector<vii> edges(100005);
int N,E,x,y,wt;
int prim(int s)
{
  priority_queue<ii,vii,greater<ii> > pq;
  int mncost=0;
  ii x;
  pq.push({0,s});
  while(!pq.empty())
  {
    x=pq.top();pq.pop();
    if(vis[x.second]) continue;
    mncost+=x.first;
    vis[x.second]=1;
    cout<<x.second+1<<"-->";
    for(auto it:edges[x.second])	if(!vis[it.second])
      pq.push(it);
  }
  return mncost;
}
int main()
{
	prep();
  cin>>N>>E;
  loop(i,E)
  {
    cin>>x>>y>>wt;
    x--;
    y--;
    edges[x].pb({wt,y});
    edges[y].pb({wt,x});
  }
  cout<<prim(0)<<"\n";
  return 0;
}
