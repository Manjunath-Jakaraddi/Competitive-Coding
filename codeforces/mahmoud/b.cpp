#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;
#define INF 1000000007
string str[100005];
ll arr[100005],arr2[100005];
int main()
{
  ll n,k,m;
  ll x,y;
  map<string,ll> mmap;
  cin>>n>>k>>m;
  for(ll i=1;i<=n;i++)  cin>>str[i];
  for(ll i=1;i<=n;i++) cin>>mmap[str[i]];
  for(ll i=0;i<k;i++)
  {
    cin>>x;
    ll mn=INT_MAX;
    for(ll j=0;j<x;j++)
    {
      cin>>arr2[j];
      mn=min(mn,mmap[str[arr2[j]]]);
    }
    for(ll j=0;j<x;j++)
      mmap[str[arr2[j]]]=mn;
  }
  ll ans=0;
  string z;
  for(ll i=0;i<m;i++)
  {
    cin>>z;
    ans+=mmap[z];
  }
  cout<<ans<<"\n";
	return 0;
}
