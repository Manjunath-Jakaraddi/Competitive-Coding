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
string s;
int cnt_same[1000006],n;
int solve()
{
  int cnt=0,i=0,j=0,ans=0;
  while(i<n)
  {
    j=i+1,cnt=1;
    while(j<n&&s[i]==s[j])  ++j,cnt++;
    ans+=(cnt*(cnt+1))>>1;
    cnt_same[i]=cnt;
    i=j;
  }
  for(int i=1;i<n-1;i++)
  {
    if(s[i]==s[i-1])  cnt_same[i]=cnt_same[i-1];
    if(s[i]!=s[i+1]&&s[i-1]==s[i+1])  ans+=min(cnt_same[i-1],cnt_same[i+1]);
  }
  
  return ans;
}
int main()
{
	prep();
	cin>>n>>s;
	cout<<solve()<<"\n";
	return 0;
}
