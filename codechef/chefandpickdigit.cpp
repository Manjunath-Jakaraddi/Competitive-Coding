#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int a[10];
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
    string s;
    cin>>s;
    fori(s.length())
    {
      a[s[i]-'0']++;
    }
    for(int i=65;i<=90;i++)
    {
      int x=i/10,y=i%10;
      if(x==y&&a[x]&&!(a[x]&1))
      {
        cout<<(char)i;
      }
      else if(a[x]&&a[y])
      {
        cout<<char(i);
      }
    }
  }
  return 0;
}
