#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,wt;
  cin>>n>>wt;
  int val[n+1],w[n+1];
  int knap[n+1][wt+1]={{0}};
  for(int i=0;i<n;i++)  cin>>w[i];
  for(int i=0;i<n;i++)  cin>>val[i];
  for(int i=0;i<=n;i++)
    for(int j=0;j<=wt;j++)
      knap[i][j]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=wt;j++)
    {
      if(j-w[i-1]>=0)
        knap[i][j]=max(val[i-1]+knap[i-1][j-w[i-1]],knap[i-1][j]);
      else
        knap[i][j]=knap[i-1][j];
    }
  }
  for(int i=0;i<=n;i++)
  {
    for(int j=0;j<=wt;j++)
    {
      cout<<knap[i][j]<<" ";
    }
    cout<<"\n";
  }
  int W=wt,res=knap[n][wt];
  for(int i=n;i>0&&res>0;i--)
  {
    if(res==knap[i-1][W]) continue;
    else
    {
      cout<<i<<" ";
      res-=val[i-1];
      W-=w[i-1];
    }
  }
  cout<<knap[n][wt];
}
