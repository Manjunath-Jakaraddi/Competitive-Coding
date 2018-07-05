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
int n,k;
int has[100005];
string s;
void solve(int cnt)
{
  for(int i=0;i<ceil((double)s.length()/2);i++)
  {
    int req=2;
    if((s.length()&1)&&(i==(s.length()/2)+1))  req=1;
    if(s[i]==s[n-1-i]&&cnt+req<=k&&s[i]!='9')
    {
        s[i]=s[n-1-i]='9';
        cnt+=req;
    }
    else if(s[i]!=s[n-1-i])
    {
      if(s[i]=='9'||s[n-1-i]=='9')  s[i]=s[n-1-i]='9';
      else
      {
          if(cnt+1<=k)
          {
              s[i]=s[n-1-i]='9';
              cnt++;
          }
          else
          {
              char ch=max(s[i],s[n-1-i]);
              s[i]=s[n-1-i]=ch;
          }
      }
    }
  }
}
int main()
{
	prep();
  cin>>n>>k>>s;
  int cnt=0;
  for(int i=0;i<s.length()/2;i++)
   cnt+=(s[i]!=s[n-1-i]);
  cout<<cnt<<"\n";
  if(cnt>k) cout<<"-1\n";
  else
  {
    solve(cnt);
    cout<<s<<"\n";
  }
	return 0;
}
