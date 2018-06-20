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
ll power(ll base,ll exp)
{
  if(exp==0)  return 1;
  ll res=power(base,exp/2);
  if(exp&1) return ((res*res)%MOD*base)%MOD;
  return (res*res)%MOD;
}
ll multiply(ll a,ll b)
{
  if(b==0)  return 0;
  ll res = multiply(a,b/2);
  if(b&1) return (res+res+a)%MOD;
  return (res+res)%MOD;
}
int main()
{
	prep();
  ll n,k;
  cin>>n>>k;
  if(!n)
  {
    cout<<"0\n";
    return 0;
  }
  k++;
  ll res=power(2,k);
  ll res2=power(2,k-1);
  res=multiply(res,n);
  res= (res-res2+MOD)%MOD;
  cout<<(res+1)%MOD<<"\n";
	return 0;
}
