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
int generate(int num) {
  int res = 0;
  while(num) {
    int digit = num%10;
    num/=10;
    res+=(digit*digit);
  }
  return res;
}
int main()
{
  int num;
	prep();
  rep(i, 1, 15) {
    rep(j, 1, 20) {
      if (j == 1) num=generate(i);
      else num=generate(num);
      cout<<num<<" ";
    }
    cout<<"\n";
  }
	return 0;
}
