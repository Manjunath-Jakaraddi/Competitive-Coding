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
ll n,k,x,y,e,wt;
vector<vector<ll> > edges(1000006);
vector<bool> vis;
vector<pair<ll,pair<ll,ll> > > eprs;
vector<ll> pr,rnk;
void dfs(int s)
{
  vis[s]=true;
  for(auto it:edges[s])
    if(!vis[it])
      dfs(it);
}
bool dfscheck(ll s)
{
  vis.assign(n,0);
  pr.assign(n+1,0);
  rnk.assign(n+1,0);
  loop(i,n+1) pr[i]=i;
  dfs(s);
  loop(i,n) if(!vis[i]) return false;
  return true;
}
ll findSet(ll i)
{
  return (pr[i]==i)?i:(pr[i]=findSet(pr[i]));
}
ll isSameSet(ll i,ll j)
{
  return (findSet(i)==findSet(j));
}
ll unionSet(ll i,ll j)
{
  ll x=findSet(i),y=findSet(j);
  if(rnk[x]>rnk[y])	pr[y]=x;
  else
  {
    pr[x]=y;
    if(rnk[x]==rnk[y])	rnk[y]++;
  }
}
ll kruskal()
{
  ll mncost=0,cnt=0;
  vi wt;
  sort(all(eprs));
  loop(i,eprs.size())
  {
    ll w=eprs[i].first;
    ll x=eprs[i].second.first;
    ll y=eprs[i].second.second;
    if(!isSameSet(x,y))
    {
      mncost+=w;
      wt.pb(w);
      unionSet(x,y);
    }
  }
  if(mncost<=k) return 0;
  int ind=wt.size()-1;
  while(mncost>k&&ind>=0)
  {
    mncost=mncost-wt[ind]+1;
    ind--;cnt++;
  }
  if(mncost>k) return -1;
  return cnt;
}
int main()
{
	prep();
  cin>>n>>e>>k;
  loop(i,n)
  {
      cin>>x>>y>>wt;
      x--;y--;
      edges[x].pb(y);
      edges[y].pb(x);
      eprs.pb({wt,{x,y}});
  }
  if(!dfscheck(0)) cout<<"-1\n";
  else  cout<<kruskal()<<"\n";
  return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define N 1000005
// pair<ll,pair<int,int> > p[N];
// ll n,m,pr[N],a=0,k;
// vector<int> v[N];
// bool vis[N];
// void initialize()
// {
//   for(int i=1;i<=n;i++) pr[i]=i;
// }
// int root(int i)
// {
//   return (pr[i]==i)?i:(pr[i]=root(pr[i]));
// }
// void dfs(int s)
// {
//   vis[s]=true;
//   a++;
//   for(auto it:v[s])
//     if(!vis[it])
//       dfs(it);
// }
// void union1(int x,int y)
// {
//   x=root(x);y=root(y);
//   pr[x]=pr[y];
// }
// int kruskal()
// {
//   ll mncost=0,cnt=0;
//   vector<int> wt;
//   for(int i=0;i<m;i++)
//   {
//     ll w=p[i].first;
//     int x=p[i].second.first,y=p[i].second.second;
//     if(root(x)!=root(y))
//     {
//       mncost+=w;
//       wt.push_back(w);
//       union1(x,y);
//     }
//   }
//   if(mncost<=k) return 0;
//   reverse(wt.begin(),wt.end());
//   for(auto it:wt)
//   {
//     mncost=mncost-it+1;
//     cnt++;
//     if(mncost<=k) return cnt;
//   }
//   return -1;
// }
// int main()
// {
//   cin>>n>>m>>k;
//   initialize();
//   int x,y;
//   ll w;
//   for(int i=0;i<m;i++)
//   {
//     cin>>x>>y>>w;
//     p[i]={w,{x,y}};
//     v[x].push_back(y);
//     v[y].push_back(x);
//   }
//   dfs(1);
//   if(a<n)
//   {
//     cout<<"-1\n";
//     return 0;
//   }
//   sort(p,p+m);
//   cout<<kruskal()<<"\n";
//   return 0;
// }
