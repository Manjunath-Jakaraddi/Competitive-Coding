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
int m;
string s;
int main()
{
	prep();
  cin>>s>>m;
  set<char> st;
  map<char,int> mmap;
  int start=0,end=0,mx=0,n=s.length();
  while(start<n&&end<n&&start<=end)
  {
    if(st.size()>m)
    {
      mmap[s[start]]--;
      if(mmap[s[start]]==0) st.erase(s[start]);
      start++;
    }
    else if(st.size()<=m)
    {
      if(st.size()==m)
      {
        mx=max(mx,end-start+1);
        cout<<start<<" "<<end<<"\n";
      }
      mmap[s[end]]++;
      if(mmap[s[end]]==1) st.insert(s[end]);
      end++;
    }
  }
  cout<<mx<<"\n";
  return 0;
}
