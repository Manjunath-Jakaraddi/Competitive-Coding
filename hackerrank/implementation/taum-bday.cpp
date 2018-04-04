#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long B,W;
  long long x,y,z;
  int t;
  cin>>t;
  while(t--)
  {
    cin>>B>>W;
    cin>>x>>y>>z;
    long long cost=B*min(x,y+z);
    cost+=W*min(y,x+z);
    cout<<cost<<"\n";
  }
  return 0;
}
