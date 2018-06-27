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
ll x,y,c,a,b,d;
void extendedEuclid(ll a,ll b)
{
  if(b==0)
  {
    x=1;y=0;d=a;
    return;
  }
  extendedEuclid(b,a%b);
  ll x1=y;
  ll y1=x-(a/b)*y;
  x=x1;
  y=y1;
  cout<<x<<" "<<y<<"\n";
}
int main()
{
	prep();
  cin>>c>>a>>b;
  extendedEuclid(a,b);
  if(c%a==0)
  {
    cout<<"YES\n"<<c/a<<" 0\n";
  }
  else if(c%b==0)
  {
    cout<<"YES\n0 "<<c/b<<"\n";
  }
  else if(c%d==0)
  {
    ll x0=(ll)x*(c/d),y0=(ll)y*(c/d);
    cout<<x0<<" "<<y0<<"\n";
    cout<<x<<" "<<y<<"\n";
    int res1=x0,res2=y0;
    cout<<x0<<" "<<y0<<"\n";
    for(int i=1;i<100000000;i++)
    {
      if(res2>0)  res1=(x0+(b/d)*i),res2=(y0-(a/d)*i);
      else if(res1>0) res1=(x0-(b/d)*i),res2=(y0+(a/d)*i);
      // cout<<res1<<" "<<res2<<"\n";
      if(res1>0&&res2>0)  break;
    }
    cout<<"YES\n"<<res1<<" "<<res2<<"\n";
  }
  else
    cout<<"NO\n";
	return 0;
}
