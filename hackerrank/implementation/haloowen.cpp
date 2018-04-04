#include<bits/stdc++.h>
using namespace std;
int main()
{
  int p,d,m,cost;
  cin>>p>>d>>m>>cost;
  int cnt=0;
  while(cost>=p)
  {
    cost-=p;
    p=p-d>=m?p-d:m;
    cnt++;
  }
  cout<<cnt<<"\n";
  return 0;
}
