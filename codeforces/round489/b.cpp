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
int main()
{
	prep();
  ll l,r,x,y;
  sf("%lld%lld%lld%lld",&l,&r,&x,&y);
  if(y%x)
  {
    pf("0\n");
    return 0;
  }
  ll t=y/x;
  vector<ll> fact;
  for(int i=2;i<=t;i++)
  {
    if(t%i) continue;
    ll v=1;
    while(t%i==0)
    {
      v*=i;
      t/=i;
    }
    fact.pb(v);
  }
  ll cnt=0;
  for(int i=0;i<(1<<(int)fact.size());i++)
  {
    ll v1=x,v2=x;
    for(int j=0;j<(int)fact.size();j++)
    {
      if(i&(1<<j))  v1*=fact[j];
      else  v2*=fact[j];
    }
    if(v1>=l&&v1<=r&&v2>=l&&v2<=r)  cnt++;
  }
	pf("%lld\n",cnt);
  return 0;
}
