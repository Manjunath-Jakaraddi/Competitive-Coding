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
int n,x,y,ch,q,clks;
vi pre,post;
vector<vi> edges;
void dfs(int s)
{
  clks++;
  pre[s]=clks;
  for(auto it:edges[s]) if(pre[it]==-1)  dfs(it);
  clks++;
  post[s]=clks;
}
int main()
{
	prep();
  cin>>n;
  pre.assign(n,-1);post.assign(n,0);edges.assign(n,vi());
  loop(i,n-1)
  {
    cin>>x>>y;
    x--;y--;
    edges[x].pb(y);
  }
  loop(i,n) sort(all(edges[i]));
  loop(i,n) if(pre[i]==-1) dfs(i);
  loop(i,n) cout<<pre[i]<<" ";
  cout<<"\n";
  loop(i,n) cout<<post[i]<<" ";
  cout<<"\n";
  cin>>q;
  while(q--)
  {
    cin>>ch>>x>>y;
    x--;y--;
    if(!ch&&((pre[y]-pre[x]>=0)&&(post[x]-post[y]>=0)))
      cout<<"YES\n";
    else if(ch&&(pre[y]-pre[x]<=0)&&(post[x]-post[y]<=0))
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
	return 0;
}
