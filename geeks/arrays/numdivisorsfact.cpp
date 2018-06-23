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
bitset<50004> bs;
vi primes;
void sieve()
{
  int _sieve_size=50000;
  bs.set();
  bs[0]=bs[1]=0;
  for(int i=2;i<=_sieve_size;i++) if(bs[i])
  {
    for(int j=i*i;j<=_sieve_size;j++) bs[j]=0;
    primes.pb(i);
  }
}
ll divisors(int n)
{
  ll ans=1;
  for(auto PF:primes)
  {
    int cnt=0;
    int k=PF;
    while((n/k)!=0)
    {
      cnt+=(n/k);
      k*=PF;
    }
    ans*=(cnt+1);
  }
  return ans;
}
int main()
{
	prep();
  sieve();
  cout<<divisors(2);
  cout<<divisors(3);
  cout<<divisors(4);
	return 0;
}
