#include<bits/stdc++.h>
#include<algorithm>
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

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);

}

int main()
{
	prep();
  int t;
  cin>>t;
  int n;
  while(t--) {
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    int res = 0;
    vector<int> arr2, odd;
    for(int i=0; i<n; i++) if(arr[i]&1) odd.pb(arr[i]); else arr2.pb(arr[i]);
    for(int i=0; i<odd.size(); i++) arr2.pb(odd[i]);
    for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
        if(gcd(arr2[i], 2*arr2[j])>1) res++;
      }
    }
    cout<<res<<"\n";

  }
	return 0;
}

// 6 3 5 3
//
// 6 6
// 6 10
// 6 6
// 3 10
// 3 6
// 5
