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
  for(int a=1; a<1000; a++) {
    for(int b=1; b<1000; b++) {
      int c = 1000-a-b;
      if(c*c == a*a + b*b) {
        cout<<a<<" "<<b<<" "<<c<<"\n";
        cout<<a*b*c<<"\n";
        return 0;
      }
    }
  }
	return 0;
}

// Without programming:
//
// a= 2mn; b= m^2 -n^2; c= m^2 + n^2;
// a^2 + b^2 = 2 m^2 n^2 + m^4 + n^4 - 2 m^2 n^2  = m^2 + n^2 = c^2
// a + b + c = 1000;
//
// 2mn + (m^2 -n^2) + (m^2 + n^2) = 1000;
// 2mn + 2m^2 = 1000;
// 2m(m+n) = 1000;
// m(m+n) = 500;
//
// m>n;
//
// m= 20; n= 5;
//
// a= 200; b= 375; c= 425;
