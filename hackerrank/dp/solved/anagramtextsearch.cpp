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
bitset<1000> bs;
vi primes;
void sieve()
{
  bs.set();
  for(int i=2;i<1000;i++) if(bs[i])
  {
    for(int j=i+i;j<1000;j+=i)  bs[j]=0;
    primes.pb(i);
  }
}
string txt,pat;
int main()
{
	prep();
  cin>>txt>>pat;
  sieve();
  ll hashpat=1,hashtxt=1;
  for(char ch:pat)  hashpat*=primes[ch-'a'];
  for(int i=0;i<txt.length();i++)
  {
    hashtxt*=primes[txt[i]-'a'];
    if(i>=pat.length())
      hashtxt/=primes[txt[i-(int)pat.length()]-'a'];
    if(hashtxt==hashpat) cout<<"FOUND "<<i+1<<"\n";
  }
	return 0;
}
