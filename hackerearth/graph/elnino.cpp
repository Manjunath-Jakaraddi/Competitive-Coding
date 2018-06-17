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
int x,n,k,ans=0;
vector<vi> edges(200005);
int a[200005];
void dfs(int s,int depth)
{
  ans+=a[depth];
  for(auto it:edges[s])
    dfs(it,depth+1);
}
int main()
{
	prep();
  cin>>n>>k;
  rep(i,1,k)
  {
    cin>>x;
    if(x<=n)  a[x]++;
  }
  rep(i,1,n)  a[i]+=a[i-1];
  loop(i,n-1)
  {
    cin>>x;
    edges[i].pb(x);
  }
  dfs(1,0);
  cout<<ans<<"\n";
	return 0;
}
