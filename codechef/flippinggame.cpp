#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int b[101];
int dp[101];
int main()
{
  int n;
  cin>>n;
  int ans=0;
  for(int i=1;i<=n;i++)   cin>>b[i];
  for(int i=1;i<=n;i++)    dp[i]=dp[i-1]+(b[i]?1:0);
  for(int i=1;i<=n;i++)
  {
    for(int j=i;j<=n;j++)
    {
      ans=max(j-i+1-(dp[j]-dp[i-1])+dp[i-1]+dp[n]-dp[j],ans);
    }
  }
  cout<<ans;
  return 0;
}
