#include<bits/stdc++.h>
using namespace std;
int  main()
{
  int t,n;
  cin>>t;
  int mn,x;
  int ind;
  while(t--)
  {
    cin>>n;
    mn=9999999;
    for(int i=1;i<=n;i++)
    {
      cin>>x;
      if(x<mn)
      {
	mn=x;
	ind=i;
      }
    }
    cout<<ind<<endl;
  }
  return 0;
}
