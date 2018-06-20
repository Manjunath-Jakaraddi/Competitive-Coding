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
int t,n;
bool comp(ii a,ii b)
{
  if(a.first!=b.first)  return a.first<b.first;
  return a.second>b.second;
}
int main()
{
	prep();
  int x;
  cin>>t;
  while(t--)
  {
    cin>>n;
    vii prs;
    unordered_map<int,int> mmap;
    loop(i,n)
    {
      cin>>x;
      mmap[x]++;
    }
    for(auto it:mmap) prs.pb({it.second,it.first});
    sort(all(prs),comp);
    reverse(all(prs));
    for(auto it:prs)
    {
      int cnt=it.first,ele=it.second;
      while(cnt--)  cout<<ele<<" ";
    }
    cout<<"\n";
  }
	return 0;
}
