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
int arr[200005];
int n;
int main()
{
	prep();
  int t;
  cin>>t;
  while(t--) {
    cin>>n;
    loop(i,n) cin>>arr[i+1];
    for(int i=n; i>0; i--) {
      if(i+arr[i]<=n) {
        arr[i]+=arr[i+arr[i]];
      }
    }
    cout<<*max_element(arr+1, arr+n+1)<<"\n";
  }
	return 0;
}
