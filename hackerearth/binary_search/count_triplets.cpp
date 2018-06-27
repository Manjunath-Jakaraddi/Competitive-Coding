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
ll n,r;
ll arr[100005];
int main()
{
	prep();
  ll ans=0;
  map<ll,ll> mmapl,mmapr;
  cin>>n>>r;
  loop(i,n)
  {
    cin>>arr[i];
    mmapr[arr[i]]++;
  }
  if(r==1)
  {
      for(auto it:mmapr) ans=max(ans,it.second);
      cout<<((ans*(ans-1)*(ans-2))/6)<<"\n";
      return 0;
  }
  mmapl[arr[0]]++;
  mmapr[arr[0]]--;
  mmapr[arr[1]]--;
  for(int i=1;i<n-1;i++)
  {
    if(arr[i]%r==0&&mmapl[arr[i]/r]&&mmapr[arr[i]*r])
    {
      ans+=(mmapl[arr[i]/r]*mmapr[arr[i]*r]);
    }
    mmapl[arr[i]]++;
    mmapr[arr[i+1]]--;
  }
  cout<<ans<<"\n";
	return 0;
}
