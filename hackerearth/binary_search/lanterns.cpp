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
int n,l,bench;
int arr[1001];
int main()
{
	prep();
  cin>>n>>l;
  loop(i,n) cin>>arr[i];
  sort(arr,arr+n);
  rep(i,1,n)  bench=max(bench,arr[i]-arr[i-1]);
  double res1=(double)bench/2;
  double res2=max((double)arr[0],(double)(l-arr[n-1]));
  pf("%.10lf\n",max(res1,res2));
	return 0;
}
