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
#define rep(i, s, e) for(auto i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int val[100005],pow_10[100005];
int main()
{
	prep();
  string s;
  cin>>s;
  int q,l,r;
  val[0]=0;
  pow_10[0]=1;
  for(int i=0;i<=s.size();i++)
  {
    val[i+1]=(val[i]*3+s[i]-'0')%7;
    pow_10[i+1]=(pow_10[i]*3)%7;
  }
  cin>>q;
  while(q--)
  {
    cin>>l>>r;
    ll rem=(val[r]-val[l-1]*pow_10[r-l+1]+7)%7;
    if(rem==0)  cout<<"YES\n";
    else  cout<<"NO\n";
  }
  return 0;
}
