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
ll n,reqdprod;
vector<ll> mach;
int prod(ll days)
{
  ll sm=0;
  loop(i,n)   sm+=(days/mach[i]);
  return (sm>=reqdprod);
}
int main()
{
	prep();
  cin>>n>>reqdprod;
  mach.assign(n,0);
  loop(i,n) cin>>mach[i];
  ll lo=1,hi=(100000LL*(INT_MAX));
  while(lo<hi)
  {
    ll mid=(lo+hi)>>1;
    if(prod(mid))   hi=mid;
    else lo=mid+1;
  }
  cout<<lo<<"\n";
	return 0;
}
