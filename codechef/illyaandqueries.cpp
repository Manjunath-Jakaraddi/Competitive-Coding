#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int a[100005];
int main()
{
  int m,n,t;
  string s;
  cin>>s;
  for(int i=1;i<s.length();i++)  a[i]=a[i-1]+(s[i]==s[i-1]?1:0);
  cin>>t;
  for(int i=0;i<t;i++)
  {
    cin>>m>>n;
    cout<<a[n-1]-a[m-1]<<endl;
  }
  return 0;
}
