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
ll res[100005],p[100005],c[100005],dp[100005];
vector<pair<int,ii>> eprs;
vi mnhp;
bool comp(pair<int,ii> a,pair<int,ii> b)
{
  if(a.first!=b.first)  return a.first<b.first;
  return a.second.first>b.second.first;
}
int main()
{
	prep();
  int n,k;
  cin>>n>>k;
  loop(i,n) cin>>p[i];
  loop(i,n) cin>>c[i];
  //p c ind
  loop(i,n) eprs.pb({p[i],{c[i],i}});
  sort(all(eprs),comp);
  ll sm=0;
  res[eprs[0].second.second]=eprs[0].second.first;
  for(int i=1;i<eprs.size();i++)
  {
    if(i<=k)
    {
      mnhp.pb(eprs[i-1].second.first);
      sm+=eprs[i-1].second.first;
      push_heap(all(mnhp),greater<int>());
    }
    if(i>k&&mnhp.size()!=0)
    {
      int ele=mnhp.front();
      if(ele<eprs[i-1].second.first)
      {
        sm=sm-ele+eprs[i-1].second.first;
        pop_heap(all(mnhp),greater<int>());
        mnhp.pop_back();
        mnhp.pb(eprs[i-1].second.first);
        push_heap(all(mnhp),greater<int>());
      }
    }
    res[eprs[i].second.second]=sm+eprs[i].second.first;
  }
  loop(i,n) cout<<res[i]<<" ";
  return 0;
}
