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
  int first=0, second=1;
  int i=1;
  ll curr=0, ans=0;
  while(curr<=4000000)
  {
    curr=first+second;
    if(curr%2==0) ans+=curr;
		first=second;
		second=curr;
  }
  cout<<ans<<"\n";
	return 0;
}
