#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int a[505],b[505];
int main()
{
  int n,k,cnt=0;
  cin>>n>>k;
  fori(n) cin>>a[i];
  for(int i=0;i<n;i++)
  {
    if(i==0)  b[i]=a[i];
    else  b[i]=max(k-b[i-1],a[i]);
    cnt+=b[i]-a[i];
  }
  cout<<cnt<<endl;
  fori(n) cout<<b[i]<<" ";
  return 0;
}
