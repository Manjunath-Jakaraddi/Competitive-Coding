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
ll _sieve_size;
bitset<10000010> bs;
vi primes;
void sieve(ll upperbound)
{
  _sieve_size = upperbound+1;
  bs.set();
  bs[0]=bs[1]=0;
  for(ll i=2;i<=_sieve_size;i++)  if(bs[i])
  {
    for(ll j=i*i;j<=_sieve_size;j+=i)  bs[j]=0;
    primes.pb(i);
  }
}
bool isPrime(ll N)
{
  if(N<=_sieve_size)  return bs[N];
  for(int i=0;i<(int)primes.size();i++)
    if(N%primes[i]==0)  return false;
  return true;
}
vi primeFactors(ll N)
{
  vi factors;
  ll PF_idx=0,PF=primes[PF_idx];
  while(PF*PF<=N)
  {
    while(N%PF==0)  { N/=PF; factors.pb(PF); }
    PF=primes[PF_idx++];
  }
  if(N!=1) factors.pb(N);
  return factors;
}
vi diffPF(ll N)
{
  vi factors;
  ll PF_idx=0,PF=primes[PF_idx];
  while(PF*PF<=N)
  {
    if(N%PF==0) factors.pb(PF);
    while(N%PF==0) N/=PF;
    PF=primes[PF_idx++];
  }
  if(N!=1) factors.pb(N);
  return factors;
}
ll numOfDivisors(ll N)
{
  ll PF_idx=0,PF=primes[PF_idx],num_of_divisors=1,power;
  while(PF*PF<=N)
  {
    power=0;
    while(N%PF==0)  { N/=PF; power++; }
    PF=primes[PF_idx++];
    num_of_divisors*=(power+1);   //formula for number of divisors
  }
  if(N!=1)  num_of_divisors*=2;
  // cout<<"Divisors : "<<num_of_divisors<<"\n";
  return num_of_divisors;
}
ll sumOfDivisors(ll N)
{
  ll PF_idx=0,PF=primes[PF_idx],ans=1;
  while(PF*PF<=N)
  {
    ll power=0;
    while(N%PF==0) { N/=PF; power++; }
    ans*=((ll)pow((double)PF,power+1.0)-1)/(PF-1);
    PF = primes[PF_idx++];
  }
  if(N!=1)  ans*=((ll)pow((double)N,2.0))/(N-1);
  // cout<<"SUM : "<<ans<<"\n";
  return ans;
}
// φ(N) = N × Prod(pf) (1 − 1/P F )
ll EulerPhi(ll N)
{
  ll PF_idx=0,PF=primes[PF_idx],ans=N;
  while(PF*PF<=N)
  {
    if(N%PF==0) ans-=ans/PF;
    while(N%PF==0)  N/=PF;
    PF=primes[PF_idx++];
  }
  if(N!=1)  ans-=ans/N;
  return ans;
}

ll Phi[10000010];
ll _sieve_EulerPhi_size;
void sieve_EuelerPhi(ll upperbound)
{
  _sieve_EulerPhi_size=upperbound+1;
  for(int i=1;i<=_sieve_EulerPhi_size;i++)  Phi[i]=i;
  for(int i=2;i<=_sieve_EulerPhi_size;i++)
    if(Phi[i]==i)
      for(int j=i;j<=_sieve_EulerPhi_size;j+=i)
        Phi[j]-=Phi[j]/i;
}
ll Pillai[10000010];
ll _sieve_Pillai_size;
void sieve_Pillai(ll upperbound)
{
  _sieve_Pillai_size=upperbound+1;
  for(int i=2;i<=_sieve_Pillai_size;i++)
    for(int j=i;j<=_sieve_Pillai_size;j+=i)
      Pillai[j]+=(i*Phi[j/i]);
}
ll numDiffPF[10000010];
ll _sieve_numDiff_size;
void sieve_numDiff(ll upperbound)
{
  _sieve_numDiff_size=upperbound+1;
  for(int i=2;i<=_sieve_numDiff_size;i++)
    if(numDiffPF[i]==0)
      for(int j=i;j<=_sieve_numDiff_size;j+=i)
        numDiffPF[j]++;
}
int main()
{
	prep();
  // For All the Sieve apply modular
  sieve(10000000);
  sieve_EuelerPhi(10000000);
  sieve_Pillai(10000000);
  sieve_numDiff(10000000);
	loop(i,26)	cout<<primes[i]<<"\n";
  pf("Last Prime : %d\n",primes[(int)primes.size()-1]);
  pf("Is Prime : %d\n",isPrime(142391208960LL));
  vi r1=primeFactors(142391208960LL);
  vi r2=diffPF(142391208960LL);
  ll numDivisors = numOfDivisors(142391208960LL);
  ll smDivisors= sumOfDivisors(142391208960LL);
  cout<<"Prime Factors of (142391208960) : ";
  for(auto it:r1) cout<<it<<" ";  cout<<"\n";
  cout<<"Distinct Prime Factors of (142391208960) : ";
  for(auto it:r2) cout<<it<<" "; cout<<"\n";
  cout<<"Num of Divisors of (142391208960) : "<<numDivisors<<"\n";
  cout<<"Sum of Divisors of (142391208960) : "<<smDivisors<<"\n";
  cout<<"Euler Phi(36): "<<EulerPhi(36)<<"\n";
  cout<<"Phi Values : ";
  rep(i,2,10) cout<<Phi[i]<<" ";  cout<<"\n";
  cout<<"Pillai value or SUM[gcd(k,n)] : ";
  rep(i,2,10) cout<<Pillai[i]<<" ";  cout<<"\n";
  cout<<"Number of Distinct Primes Factors : ";
  rep(i,2,10) cout<<numDiffPF[i]<<" ";  cout<<"\n";
  cout<<"GCD of (167616,96800) : "<< __gcd(167616,96800)<<"\n";
  cout<<"LCM of (167616,96800) : "<<(167616*(96800/__gcd(167616,96800)))<<"\n";
	return 0;
}
