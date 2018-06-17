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
#define N 100005
vector<pair<ll,ii> > eprs;
vector<ll> val;
int pr[N];
int n,e,x,y,wt,k;
void initialize()
{
  for(int i=1;i<=n;i++) pr[i]=i;
}
int root(int i)
{
  return (pr[i]==i)?i:(pr[i]=root(pr[i]));
}
void union1(int x,int y)
{
  x=root(x),y=root(y);
  pr[x]=pr[y];
}
ll kruskal()
{
  vector<ll> wts;
  for(int i=0;i<e;i++)
  {
    ll w=eprs[i].first;
    int x=eprs[i].second.first,y=eprs[i].second.second;
    if(root(x)!=root(y))
    {
      union1(x,y);
      wts.pb(w);
    }
  }
  int totalind=wts.size();
  wts.insert(wts.end(),all(val));
  sort(all(wts));
  ll res=accumulate(wts.begin(),wts.begin()+totalind,0LL);
  return res;
}
int main()
{
	prep();
  cin>>n>>e;
  initialize();
  loop(i,e)
  {
    cin>>x>>y>>wt;
    eprs.pb({wt,{x,y}});
  }
  cin>>k;
  loop(i,k)
  {
    cin>>x;
    val.pb(x);
  }
  sort(all(val));
  sort(all(eprs));
  cout<<(1LL*kruskal())<<"\n";
  return 0;
}
