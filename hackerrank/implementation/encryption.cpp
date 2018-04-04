#include<bits/stdc++.h>
using namespace std;
int main()
{
  string str;
  cin>>str;
  int n=str.length();
  int col=ceil(sqrt(n));
  for(int i=0;i<col;i++)
  {
    for(int j=0;i+j<n;j+=col)
    {
      cout<<str[i+j];
    }
    cout<<" ";
  }
  return 0;
}
