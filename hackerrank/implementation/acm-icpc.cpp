#include<bits/stdc++.h>
using namespace std;
string arr[500];
int n,m;
int OR(int i,int j)
{
  int cnt=0;
  for(int k=0;k<m;k++)  if((arr[i][k]-'0')|arr[j][k]-'0') cnt++;
  return cnt;
}
void solve()
{
  int mx=0,cnt=0;
  unordered_map<int,int> um;
  for(int i=0;i<n-1;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      int x=OR(i,j);
      if(mx<=x)
      {
        mx=x;
        um[mx]++;
      }
      // mx=max(mx,OR(i,j));
    }
    // um[mx]++;
  }
  cout<<mx<<"\n"<<um[mx]<<"\n";
}
int main()
{
  cin>>n>>m;
  for(int i=0;i<n;i++)  cin>>arr[i];
  solve();
  return 0;
}
