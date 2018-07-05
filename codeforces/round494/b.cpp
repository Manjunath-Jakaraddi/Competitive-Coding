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
int main()
{
	prep();
  int o,z,x;
  cin>>z>>o>>x;
  string s="";
  if(o<z)
  {
    for(int i=0;i<x/2;i++)
    {
      s.pb('0');
      s.pb('1');
      o--;z--;
    }
    if(x&1)
    {
      while(z--)  s="0"+s;
      while(o--)  s.pb('1');
    }
    else
    {
      while(o--)  s.pb('1');
      while(z--)  s.pb('0');
    }
  }
  else
  {
    for(int i=0;i<x/2;i++)
    {
      s.pb('1');
      s.pb('0');
      o--;z--;
    }
    // cout<<o<<" "<<z<<"\n";
    if((x&1))
    {
      while(o--)  s="1"+s;
      while(z--)  s.pb('0');
    }
    else
    {
      while(z--)  s.pb('0');
      while(o--)  s.pb('1');
    }
  }
  cout<<s<<"\n";
	return 0;
}
