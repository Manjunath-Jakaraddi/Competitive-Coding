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
int n,m,x,y,clks,evncnt,oddcnt,cnt,bi=-1;
vi vis,par,disc,lowlink;
vector<vi> edges;
vector<vii> bicomp;
stack<ii> st;
void dfs(int s)
{
  clks++;
  vis[s]=1;
  disc[s]=lowlink[s]=clks;
  int child=0;
  for(auto it:edges[s])
  {
    if(!vis[it])
    {
      par[it]=s;
      child++;
      st.push({s,it});
      dfs(it);
      lowlink[s]=min(lowlink[s],lowlink[it]);
      if(disc[s]<=lowlink[it])
      {
        bi++;
        bicomp.pb(vii());
        while(st.top().first!=s&&st.top().second!=it)
        {
          bicomp[bi].pb({st.top().first,st.top().second});
          st.pop();
        }
        bicomp[bi].pb({st.top().first,st.top().second});
        st.pop();
      }
    }
    else if(par[s]!=it)
    {
      lowlink[s]=min(lowlink[s],disc[it]);
      st.push({s,it});
    }
  }
}
int main()
{
	prep();
  cin>>n>>m;
  vis.assign(n,0);disc.assign(n,0);lowlink.assign(n,0),par.assign(n,-1);edges.assign(n,vi());
  loop(i,m)
  {
    cin>>x>>y;
    edges[x].pb(y);
    edges[y].pb(x);
  }
  loop(i,n) if(!vis[i]) dfs(i);
  cnt=0;
  while(!st.empty())
  {
    cnt++;
    st.pop();
  }
  if(cnt)
    if(cnt==1)  evncnt++;
    else if(cnt&1)  oddcnt++;
    else  evncnt++;
  cout<<oddcnt<<" "<<evncnt<<"\n";
	return 0;
}
