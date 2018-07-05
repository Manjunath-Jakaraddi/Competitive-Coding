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
ll n;
ll arr[100005];
ll pow2[100005];
ll multiply(ll a,ll b)
{
    if(b==0)    return 0;
    ll res=multiply(a,b/2);
    if(b&1) return (res+res+a)%MOD;
    return (res+res)%MOD;
}
int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i];
  pow2[0]=1;
  rep(i,1,n)  pow2[i]=(pow2[i-1]*2)%MOD;
  ll curr=(pow2[n]-1+MOD)%MOD;
  ll res=0;
  // cout<<res<<"\n";
  cout<<curr<<"\n";
  loop(i,n/2)
  {
    ll mul=(arr[i]+arr[n-1-i])%MOD;
    res=(res+(multiply(mul,curr))%MOD)%MOD;
    curr=(curr+
          (((pow2[n-2-i]-pow2[i])%MOD+MOD)%MOD)
         )%MOD;
    // cout<<i<<" "<<res<<"\n";
    cout<<curr<<"\n";
  }
  if(n&1) res=(res+(multiply(arr[n/2],curr))%MOD)%MOD;
  cout<<res<<"\n";
	return 0;
}
