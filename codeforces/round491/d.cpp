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
int cnt[105];
int main()
{
	prep();
  string s1,s2;
  cin>>s1>>s2;
  int n=s1.length();
  loop(i,n) cnt[i+1]+=(s1[i]=='0')+(s2[i]=='0');
  int res=0;
  rep(i,1,n)
  {
    if(cnt[i]==2&&cnt[i+1])
    {
      res++;
      cnt[i]=0;
      cnt[i+1]--;
    }
    else if(cnt[i]&&cnt[i+1]==2)
    {
      res++;
      cnt[i+1]=cnt[i]=0;
    }
  }
  cout<<res<<"\n";
	return 0;
}
