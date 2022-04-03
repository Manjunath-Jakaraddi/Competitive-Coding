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
// 000101
int main()
{
	prep();
  int n;
  cin>>n;
  int second = (n&(1<<4));
  int third = (n&(1<<3));
  int fourth = (n&(1<<2));
  int sixth = (n&1);
  int first = (n&(1<<5));
  int fifth = (n&(1<<1));
  int res = 0;
  res|=(first ? (1<<5) : 0);
  res|=(second ? 1 : 0);
  res|=(third ? (1<<2) : 0);
  res|=(fourth ? (1<<3) : 0);
  res|=(fifth ? (1<<1) : 0);
  res|=(sixth ? (1<<4) : 0);
  cout<<res<<"\n";
	return 0;
}
