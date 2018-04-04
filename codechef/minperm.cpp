#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int a[100005];

int main()
{
  int n,t;
  cin>>t;
  while(t--)
  {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
      if(i&1)
      {
        a[i+1]=i;
      }
      else
      {
        a[i-1]=i;
      }
    }
    if(n&1)
    {
      a[n]=a[n-1];
      a[n-1]=n;
    }
    for(int i=1;i<=n;i++)
    {
      cout<<a[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
