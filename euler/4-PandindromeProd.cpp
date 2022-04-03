#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define pb push_back
#define pf printf
#define sf scanf
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(auto i=s; i<=e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int main()
{
	prep();
  string str1,str2;
  ll resi,resj,mxprod=-1;
  for(int i=999;i>=100;i--)
  {
    for(int j=999;j>=100;j--)
    {
      str1=to_string(i*j);
      str2=str1;
      reverse(all(str2));
      if(str1==str2)
      {
        if(mxprod<(i*j))
        {
          mxprod=i*j;
          resi=i;
          resj=j;
        }
      }
    }
  }
  cout<<resi<<" "<<resj<<"\n";
  return 0;
}
