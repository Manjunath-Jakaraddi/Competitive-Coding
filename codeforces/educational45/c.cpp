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
int n,cnt;
string s;
int getcount()
{
  int i;
  cin>>s;
  stack<char> st;
  for(i=0;i<s.length();i++)
  {
    if(st.empty()) st.push(s[i]);
    else if(st.top()=='(')
    {
      if(s[i]==')') st.pop();
      else  st.push(s[i]);
    }
    else st.push(s[i]);
  }
  int c=st.size(),z=0;
  while(!st.empty())
  {
    if(st.top()=='(')  z++;
    else  z--;
    st.pop();
  }
  if(c==abs(z)) return z;
  return INT_MIN;
}
int main()
{
	prep();
  cin>>n;
  ll ans=0;
  map<int,int> mmap;
  loop(i,n)
  {
    cnt=getcount();
    if(cnt!=INT_MIN)
    {
      // cout<<cnt<<"\n";
      if(cnt==0)
        ans+=mmap[0]*2+1;
      else
        ans+=mmap[-cnt];
      // cout<<cnt<<" "<<ans<<"\n";
      mmap[cnt]++;
    }
  }
  cout<<(1LL*ans)<<"\n";
  return 0;
}
