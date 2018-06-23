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
// Equation ax+by=c d=gcd(a,b)
// # 3 Cases 1) if d do divide c no solution
//           2) if d==c unique solution(x0,y0) i.e ax+by=gcd(a,b)
//           3) if d divide c infinite solution x = x0+(b/d)n and y=y0-(a/d)n
int x,y,d;
void extendedEuclid(int a,int b)
{
  if(b==0) { x=1;y=0;d=a; return; }
  extendedEuclid(b,a%b);
  int x1=y;
  int y1=x-(a/b)*y;
  x=x1;
  y=y1;
}
int main()
{
	prep();
  // 25x+18y=1
  extendedEuclid(25,18);
  cout<<x<<" "<<y<<"\n";
	return 0;
}
