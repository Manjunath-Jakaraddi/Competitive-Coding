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

ll n,res;
bool solve(ll cur,ll k)
{
  ll ate=0;
  while(cur)
  {
    ate+=min(cur,k);
    cur-=min(cur,k);
    cur-=(cur/10);
  }
  return (2*ate>=n);
}
ll bin(ll lo,ll hi)
{
  while(lo<hi)
  {
    ll md=(hi+lo)/2;
    if(solve(n,md))
      hi=md;
    else
      lo=md+1;
  }
  return lo;
}
int main()
{
	prep();
  cin>>n;
  cout<<bin(1,n)<<"\n";
	return 0;
}
