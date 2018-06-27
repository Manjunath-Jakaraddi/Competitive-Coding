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
int q;
void solve()
{
  string s1,s2;
  cin>>s1>>s2;
  int n=s1.length(),m=s2.length();
  string capt1="",capt2="";
  loop(i,n) if(s1[i]>='A'&&s1[i]<='Z')  capt1.pb(s1[i]);
  loop(i,m) if(s2[i]>='A'&&s2[i]<='Z')  capt2.pb(s2[i]);
  if(capt1.length()>capt2.length())
  {
    cout<<"NO\n";
    return;
  }
  else if(capt1.length()==capt2.length())
  {
    if(capt1==capt2)  cout<<"YES\n";
    else  cout<<"NO\n";
    return;
  }
  s1=" "+s1;
  s2=" "+s2;
  int dp[n+1][m+1];
  loop(i,n+1) loop(j,m+1) dp[i][j]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=m;j++)
    {
      if(toupper(s1[i])==s2[j])   dp[i][j]=1+dp[i-1][j-1];
      else  dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
  }
  // loop(i,n+1) loop(j,m+1) cout<<dp[i][j]<<((j==m)?"\n":" ");
  cout<<((dp[n][m]==m)?"YES":"NO")<<"\n";
}
int main()
{
	prep();
  cin>>q;
  while(q--)  solve();
	return 0;
}
