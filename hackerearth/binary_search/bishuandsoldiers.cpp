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
int n;
vi power,sm;
int main()
{
	prep();
  cin>>n;
  power.assign(n,0);sm.assign(n,0);
  loop(i,n)
    cin>>power[i];
  sort(all(power));
  loop(i,n)
  {
    sm[i]=power[i];
    if(i) sm[i]+=sm[i-1];
  }
  int q,x;
  cin>>q;
  while(q--)
  {
    cin>>x;
    int ind=upper_bound(all(power),x)-power.begin();
    cout<<ind<<" "<<sm[ind-1]<<"\n";
  }
	return 0;
}
