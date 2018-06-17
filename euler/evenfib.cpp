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
int fib[100005];
int main()
{
	prep();
  fib[0]=1;
  fib[1]=2;
  int i=1;
  ll ans=0;
  while(fib[i]<=4000000)
  {
    fib[i+1]=fib[i-1]+fib[i];
    if(fib[i]%2==0) ans+=fib[i];
    i++;
  }
  cout<<ans<<"\n";
	return 0;
}
