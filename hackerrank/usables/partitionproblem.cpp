#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;i++)
int t,n;
int arr[55];
int main()
{
  cin>>t;
  while(t--)
  {
    cin>>n;
    int sm=0;
    loop(i,n)
    {
      cin>>arr[i];
      sm+=arr[i];
    }
    if(n==1)
    {
      cout<<sm<<"\n";
      continue;
    }
    int W=sm/2;
    int dp[W+1];
    fill(dp,dp+W+1,INT_MIN);
    dp[0]=0;
    for(int i=0;i<n;i++)
      for(int j=W;j>=0;j--)
        if(dp[j]!=INT_MIN&&j+arr[i]<=W)
          dp[j+arr[i]]=max(dp[j+arr[i]],1+dp[j]);
    int val=-1;
    for(int j=W;j>=0;j--)
      if(dp[j]!=INT_MIN)
      {
        val=j;
        break;
      }
    cout<<abs(val-(sm-val))<<"\n";
  }
	return 0;
}
