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
map<ll,ll> mmap;
int main()
{
	prep();
  ll n,l,r;
  cin>>n;
  loop(i,n)
  {
    cin>>l>>r;
    mmap[l]++;
    mmap[r+1]--;
  }
  vector<ll> res;
  res.assign(n+1,0);
  ll sm=0,prev=-1;
  for(auto it:mmap)
  {
    if(prev==-1)
    {
      prev=it.first;
      sm+=it.second;
      continue;
    }
    res[sm]+=(it.first-prev);
    sm+=it.second;
    prev=it.first;
  }
  rep(i,1,n)  cout<<res[i]<<" ";
  cout<<"\n";
	return 0;
}
