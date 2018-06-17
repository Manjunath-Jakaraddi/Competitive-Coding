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
int t,m,c,k;
int models[22][22];  // [ C ] [ K ]
int size[22];
int memo[222][22];  // [ M ] [ C ]
int solve(int money,int g)
{
  if(money<0) return INT_MIN;
  if(g==c)  return m-money;
  if(memo[money][g])  return memo[money][g];
  int res=INT_MIN;
  for(int i=0;i<size[g];i++)  res=max(res,solve(money-models[g][i],g+1));
  return (memo[money][g]=res);
}
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    cin>>m>>c;
    memset(memo,0,sizeof memo);
    loop(i,c)
    {
      cin>>size[i];
      loop(j,size[i]) cin>>models[i][j];
    }
    int ans=solve(m,0);
    if(ans==INT_MIN)  cout<<"no solution\n";
    else  cout<<ans<<"\n";
  }
  return 0;
}
