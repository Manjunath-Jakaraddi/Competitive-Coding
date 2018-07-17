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
set<string> res;
void permute(string s,int l,int r)
{
  if(l==r)  res.insert(s);
  else
  {
    for(int i=l;i<=r;i++)
    {
      swap(s[l],s[i]);
      permute(s,l+1,r);
      swap(s[l],s[i]);
    }
  }
}
void generate(string s,int n,int m)
{
  if(n==0&&m==0)  res.insert(s);
  if(n>0) generate(s+"(",n-1,m+1);
  if(m>0) generate(s+")",n,m-1);
}
int main()
{
	prep();
  int n;
  // string s;
  // cin>>s;
  // permute(s,0,s.length()-1);
  cin>>n;
  generate("",n,0);
  for(auto it:res)  cout<<it<<"\n";
	return 0;
}
