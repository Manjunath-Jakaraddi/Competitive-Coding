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
  int idx1, idx2, res=0;
  char c;
  string str;
  while(cin>>idx1>>idx2>>c>>str) {
    if((str[idx1-1] == c) ^ (str[idx2-1] == c)) res++;
  }
  cout<<"Result : "<<res<<"\n";
	return 0;
}


// int mn, mx, res=0;
// char c;
// string str;
// while(cin>>mn>>mx>>c>>str) {
//   int cnt = 0;
//   for(char ch: str) {
//     if(ch == c) cnt++;
//   }
//   if(cnt >=mn && cnt<=mx) res++;
// }
// cout<<"Result : "<<res<<"\n";
