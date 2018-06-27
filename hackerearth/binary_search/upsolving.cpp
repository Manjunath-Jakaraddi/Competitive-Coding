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
ll n,m;
ll arr[100005];
ll noofdays(ll daily)
{
  ll reqd=1;
  ll currSum=0;
  for(ll i=1;i<=n;i++)
  {
    if(currSum+arr[i]>daily)
    {
      reqd++;
      currSum=arr[i];
    }
    else  currSum+=arr[i];
  }
  return ((reqd<=m)?1:0);
}
int main()
{
  cin>>n>>m;
  ll lo=1,hi=1LL*MOD*MOD;
  for(ll i=1;i<=n;i++)
  {
    cin>>arr[i];
    lo=max(lo,arr[i]);
  }
  while(lo<hi)
  {
    ll md=(hi+lo)>>1;
    int p=noofdays(md);
    if(p)  hi=md;
    else  lo=md+1;
  }
  cout<<lo<<"\n";
  return 0;
}
