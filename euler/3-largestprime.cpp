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
  ll num=(1LL*600851475143);
  ll ans=-1;
  ll tmp=num;
  cout<<num<<"\n";
  for(ll i=2;i<=sqrt(num)&&tmp;i++)
  {
    while(tmp%i==0)
    {
      cout<<i<<"\n";
      tmp/=i;
      ans=max(ans,i);
    }
  }
  cout<<ans<<"\n";
  return 0;
}
