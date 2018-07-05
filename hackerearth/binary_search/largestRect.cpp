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
stack<int> st;
int n;
int ht[100005];
int main()
{
	prep();
  cin>>n;
  ll ans=0;
  loop(i,n) cin>>ht[i];
  int i=0;
  while(i<n)
  {
    ll area=0;
    if(st.empty()||ht[st.top()]<=ht[i])
    {
      st.push(i);
      i++;
    }
    while(!st.empty()&&ht[st.top()]>ht[i])
    {
      int ind=st.top();st.pop();
      if(!st.empty()) area=(i-st.top()-1)*ht[ind];
      else  area=i*ht[ind];
      ans=max(ans,area);
      // cout<<ind<<" "<<i<<" "<<area<<"\n";
    }
  }
  ll area=0;
  while(!st.empty())
  {
    int ind=st.top();st.pop();
    if(!st.empty()) area=(i-st.top()-1)*ht[ind];
    else  area=i*ht[ind];
    ans=max(ans,area);
  }
  cout<<ans<<"\n";
	return 0;
}
