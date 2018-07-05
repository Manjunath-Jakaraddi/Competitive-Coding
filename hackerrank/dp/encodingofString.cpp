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
string s;
int dp[100];
int main()
{
	prep();
  cin>>s;
  n=s.length();
  dp[0]=1;
  dp[1]=1;
  for(int i=2;i<n;i++)
  {
    if(s[i-1]-'0'>0)  dp[i]+=dp[i-1];
    int num=atoi(s.substr(i-2,2).c_str());
    if(num<=26&&num>0)  dp[i]+=dp[i-2];
  }
  // rep(i,0,n)  cout<<dp[i]<<"\n";
  cout<<dp[n-1]<<"\n";
	return 0;
}
