#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007


int main()
{
  ll x=3;
  ll st=0;
  ll t;
  cin>>t;
  while(st+x<t)
  {
    st+=x;
    x*=2;
  }
  cout<<1LL*(x-(t-st)+1)<<endl;
  return 0;
}
