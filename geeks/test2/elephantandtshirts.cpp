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
ll dp[1025][102];
// (set of persons,t-shirst id)
vector<vi> arr;
int t,n;
int stoi(string &s)
{
  stringstream ss(s);
  int x;
  ss>>x;
  return x;
}
ll solve(int p_mask,int tid)
{
  if(p_mask==((1<<n)-1))  return (dp[p_mask][tid]=1);
  if(tid==101)  return 0;
  if(dp[p_mask][tid]!=-1) return dp[p_mask][tid];
  ll ans=solve(p_mask,tid+1);
  for(auto it:arr[tid])
  {
    if((1<<it)&p_mask) continue;
    ans+=solve(p_mask|(1<<it),tid+1);
  }
  ans%=MOD;
  return (dp[p_mask][tid]=ans);
}
int main()
{
  cin>>t;
  arr.assign(101,vi());
  while(t--)
  {
    rep(i,0,1024) rep(j,0,100)  dp[i][j]=-1;
    string s;
    cin>>n;
    cin.get();
    loop(i,n)
    {
      getline(cin,s);
      stringstream ss(s);
      string temp;
      while(ss>>temp)
      {
        arr[stoi(temp)].pb(i);
      }
    }
    rep(i,0,100)  sort(all(arr[i]));
    cout<<solve(0,1)<<"\n";
    rep(i,0,100)  arr[i].clear();
  }
	return 0;
}
