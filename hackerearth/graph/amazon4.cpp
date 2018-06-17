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
#define rep(i, s, e) for(auto i=s; i<e; i++)
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
  ll t,a,b,n,m;
  cin>>t;
  while(t--)
  {
    cin>>a>>b>>n;
    ll l=min(a,b),r=max(a,b)*n;
		int lcm=(a*b)/__gcd(a,b);
		while(l<r)
		{
			m=(l+r)/2;
			int k=(m/a+m/b-m/lcm);
			if(k==n)	break;
			else if(k<n)	l=m+1;
			else	r=m;
		}
		cout<<m<<"\n";
  }
  return 0;
}
