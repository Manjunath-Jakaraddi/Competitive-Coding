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
ll n,m,x,y,s_col_id;
vector<ll> dist,col_ids;
vector<vector<ll> > edges;
void bfs(ll s)
{
  dist[s]=0;
  queue<ll> q;
  q.push(s);
  while(!q.empty())
  {
    ll z=q.front();q.pop();
    for(auto it:edges[z]) if(dist[it]>dist[z]+1)
    {
      dist[it]=dist[z]+1;
      q.push(it);
    }
  }
}
int main()
{
	prep();
  cin>>n>>m;
  dist.assign(n,INT_MAX);
  col_ids.assign(n,0);
  edges.assign(n,vector<ll>());

  loop(i,m)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
  }

  loop(i,n) cin>>col_ids[i];
  cin>>s_col_id;

  bool found=false;
  loop(i,n)
    if(col_ids[i]==s_col_id&&dist[i]==INT_MAX)
    {
      found=true;
      bfs(i);
    }
  if(!found)
  {
    cout<<"-1\n";
    return 0;
  }
  ll res=INT_MAX;
  loop(i,n)
    if(dist[i]!=INT_MAX&&dist[i]!=0&&col_ids[i]==s_col_id)
      res=min(res,dist[i]);

  if(res==INT_MAX)
    cout<<"-1\n";
  else
    cout<<res<<"\n";
	return 0;
}
