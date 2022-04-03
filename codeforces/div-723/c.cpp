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
  cin>>n;
  loop(i,n) cin>>arr[i+1];
	int res = 0;
	vector<ll> prev = vector<ll>(n+1, -1L), curr = vector<ll>(n+1, -1L);
	prev[0]=0;
	for(int i=1; i<=n; i++) {
		for(int k=1; k<=i; k++) {
			if(prev[k-1]!=-1 && prev[k-1] + arr[i] >=0 ) {
				curr[k]=max(prev[k-1] + arr[i], prev[k]);
			} else {
				curr[k] = prev[k];
			}
			if(curr[k]!=-1)	res = max(res, k);
		}
		prev=curr;
		curr = vector<ll>(n+1, -1L);
		curr[0]=0;
	}
	cout<<res<<"\n";
	return 0;
}
