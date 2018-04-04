#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
long long dp[5005][5005];
// int main()
// {
//   int n,m,k;
// 	cin>>n>>m>>k;
// 	vector<int> v(n+1),vec;
// 	for(int i=1;i<=n;i++)	cin>>v[i];
// 	for(int i=1;i<=n;i++)
// 	{
// 		if(i<=m)	dp[i]=v[i]+dp[i-1];
// 		else		dp[i]=v[i]+dp[i-1]-v[i-m];
// 	}
//   //for(int i=0;i<=n;i++)	cout<<dp[i]<<" ";
// 	sort(dp+1,dp+n+1);
//   vec.push_back(dp[m]);
//   for(int i=m+1;i<=n;i+=m)
//   {
//     vec.push_back(*max_element(dp+i,dp+i+m));
//   }
//   sort(vec.rbegin(),vec.rend());
//   for(int i=0;i<vec.size();i++) cout<<vec[i]<<" ";
//   long long ans=0;
//   for(int i=0;i<k;i++)  ans+=vec[i];
// 	cout<<ans;
//   return 0;
// }
long long sum[5005];
int main()
{
  int n,m,k;
  cin>>n>>m>>k;
  for(int i=1;i<=n;i++)
  {
    cin>>sum[i];
    sum[i]+=sum[i-1];
  }
  for(int i=1;i<=k;i++)
  {
    for(int j=1;j<=n;j++)
    {
      dp[j][i]=dp[j-1][i];
      if(j>=m) dp[j][i]=max(dp[j][i],dp[j-m][i-1]+sum[j]-sum[j-m]);
    }
  }
  cout<<dp[n][k];
  return 0;
}
