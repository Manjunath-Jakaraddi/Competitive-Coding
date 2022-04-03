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
int prime[10000006];
void sieve()
{
  memset(prime,1,sizeof prime);
  vector<ll> res;
  for(int i=2;i<=10000006;i++)
  {
    if(prime[i])
    {
      res.pb(i);
      cout<<res.size()<<"\n";
      if(res.size()==10001)
      {
        cout<<res[(int)res.size()-1]<<"\n";
        break;
      }
      for(int j=i+i;j<=10000006;j+=i)  prime[j]=0;
    }
  }
}
int main()
{
	prep();
  sieve();
  return 0;
}
