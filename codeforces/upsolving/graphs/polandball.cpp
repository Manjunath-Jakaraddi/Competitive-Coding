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
int primes[] = {2,3,5,7,11,13,17,19,23,29};

bool isPrime(int n) {
    for(int prime : primes) {
      if(n==prime) return true;
      if(n%prime == 0) return false;
    }
    return true;
}

int main()
{
	prep();
  int n;
  cin>>n;
  for(int i=1;i<=1000;i++) {
    if(!isPrime(n*i+1)) {
      cout<<i<<"\n";
      return 0;
    }
  }
	return 0;
}
