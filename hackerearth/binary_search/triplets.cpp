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
int a,b,c;
ll x;
vi arra,arrb,arrc;
set<ll> sta,stb,stc;
int main()
{
	prep();
  cin>>a>>b>>c;
  loop(i,a)
  {
    cin>>x;
    sta.insert(x);
  }
  loop(i,b)
  {
    cin>>x;
    stb.insert(x);
  }
  loop(i,c)
  {
    cin>>x;
    stc.insert(x);
  }

  for(auto it:sta)  arra.pb(it);
  for(auto it:stb)  arrb.pb(it);
  for(auto it:stc)  arrc.pb(it);
  //
  // loop(i,arra.size()) cout<<arra[i]<<" "; cout<<"\n";
  // loop(i,arrb.size()) cout<<arrb[i]<<" "; cout<<"\n";
  // loop(i,arrc.size()) cout<<arrc[i]<<" "; cout<<"\n\n\n";

  a=arra.size();
  b=arrb.size();
  c=arrc.size();
  ll res=0;
  loop(i,b)
  {
    int r1=upper_bound(all(arra),arrb[i])-arra.begin();
    int r2=upper_bound(all(arrc),arrb[i])-arrc.begin();
    // cout<<r1<<" "<<r2<<"\n";
    res+=(r1*r2);
  }
  cout<<res<<"\n";
	return 0;
}
