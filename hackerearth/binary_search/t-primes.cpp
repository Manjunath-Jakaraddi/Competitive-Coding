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
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
bitset<1000010> bs;
int _sieve_size;
vector<ll> primes;
void sieve()
{
  _sieve_size=1000000;
  bs.set();
  bs[0]=bs[1]=0;
  for(ll i=2;i<=_sieve_size;i++)  if(bs[i])
  {
    for(ll j=i+i;j<=_sieve_size;j+=i)	 bs[j]=0;
    primes.pb(i);
  }
}
vector<ll> t_primes;
int n;
void tPrimes()
{
	for(ll i=0;i<primes.size();i++)	t_primes.pb(static_cast<long long>(primes[i]) * static_cast<long long>(primes[i]));
}
int main()
{
	prep();
  sieve();
	tPrimes();
	sf("%d",&n);
	ll x;
  loop(i,n)
	{
		scanf("%lld", &x);
		printf("%s\n", binary_search(t_primes.begin(), t_primes.end(), x) ? "YES" : "NO");
	}
	return 0;
}
