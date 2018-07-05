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
int main()
{
	prep();
  int q;
  cin>>q;
  while(q--)
  {
    cin>>s;
    map<string,int> mmap;
    for(int i=0;i<s.length();i++)
    {
      for(int l=1;(i+l-1)<s.length();l++)
      {
        string t=s.substr(i,l);
        sort(all(t));
        mmap[t]++;
      }
    }
    ll res=0;
    for(auto it:mmap) res+=(it.second*(it.second-1))/2;
    cout<<res<<"\n";
  }
	return 0;
}
