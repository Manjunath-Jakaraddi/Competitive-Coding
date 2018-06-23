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
ll t,n;
ll arr[100005];
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    cin>>n;
    loop(i,n) cin>>arr[i+1];
    vi dp;
    dp.assign(n+1,0);
    dp[n]=1;
    int res=0;
    for(int i=n;i>0;i--)
    {
      int sm=0;
      for(int j=i-1;j>0;j--)
      {
        sm+=arr[j];
        if(arr[i]*6>=sm)
        {
          dp[j]=max(dp[j],1+dp[i]);
          res=max(res,dp[j]);
        }
        else
          break;
      }
      rep(i,1,n)  cout<<dp[i]<<" "; cout<<"\n";
    }
    cout<<res<<"\n";
  }
  return 0;
}
