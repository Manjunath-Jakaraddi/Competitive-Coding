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
void solve(int seedCount) {
  int rows = round(sqrt(seedCount));
  if(rows*rows == seedCount) {
    cout<<rows<<" "<<rows<<"\n\n\n";
    return;
  }
  int a,b;
  if(rows*rows < seedCount) {
    a = rows;
    b = rows +1;
  } else {
    a = rows-1;
    b = rows;
  }
  int ls = abs(a*a-seedCount), ns = abs(a*b-seedCount), gs = abs(b*b -seedCount);
  int mn = min(ls, min(ns, gs));
  if(mn == ls) cout<<a<<" "<<a<<"\n\n\n";
  else if(mn == ns)  cout<<a<<" "<<b<<"\n\n\n";
  else  cout<<b<<" "<<b<<"\n\n\n";

}
int main()
{
	prep();
  for(int i=1; i<20; i++) {
    cout<<i<<":";
    solve(i);
  }
	return 0;
}
