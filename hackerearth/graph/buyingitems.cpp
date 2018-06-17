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
#define mp make_pair
const ll oo=1e18;
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int main()
{
	prep();
  int n,m,x;
  cin>>n>>m;
  if(n<=23)
  {
    ll N=(1<<n);
    ll dp[N];
    loop(i,N) dp[i]=oo;
    dp[0]=0;
    int mask[m]={0},cost[m];
    loop(i,m)
    {
      loop(j,n)
      {
        cin>>x;
        mask[i]|=(x*(1<<j));
      }
      cin>>cost[i];
    }
    loop(msk,N)
      loop(i,m)
        dp[msk|mask[i]]=min(dp[msk|mask[i]],dp[msk]+cost[i]);
    if(dp[N-1]!=oo) cout<<dp[N-1]<<"\n";
    else  cout<<"-1\n";
  }
  else
  {
    bitset<500> mask[m];
    int cost[m];
    loop(i,m)
    {
      loop(j,n)
      {
        cin>>x;
        if(x) mask[i][j]=1;
      }
      cin>>cost[i];
    }
    int N=(1<<m);
    ll res=oo;
    loop(msk,N)
    {
      ll tcost=0;
      bitset<500> W;
      for(int i=0;i<m;i++)
        if((msk>>i)&1)
          W|=mask[i],tcost+=cost[i];
      if(W.count()==n)  res=min(res,tcost);
    }
    if(res!=oo) cout<<res<<"\n";
    else  cout<<"-1\n";
  }
  return 0;
}
