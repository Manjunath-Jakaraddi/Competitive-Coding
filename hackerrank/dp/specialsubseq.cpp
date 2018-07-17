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
vector<string> res;
void generate(string inp,string ot,int idx)
{
  if(idx==inp.size())
  {
    if(ot.size()) res.pb(ot);
    return;
  }
  // Exclusion
  generate(inp,ot,idx+1);
  // Inclusion
  ot.pb(inp[idx]);
  generate(inp,ot,idx+1);
  // Change Case
  ot.pop_back();
  ot.pb(inp[idx]-'a'+'A');  
  // Inclusion only
  generate(inp,ot,idx+1);
}
int main()
{
    prep();
    int t;
    cin>>t;
    while(t--)
    {
      string s;
      cin>>s;
      generate(s,"",0);
      sort(all(res));
      cout<<res.size()<<"\n";
      for(auto it:res)  cout<<it<<" ";
      cout<<"\n";
      res.clear();
    }
    return 0;
}
