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

ll dp[2005][2005];
int arr[2005];
int n;

int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i+1];
	memset(dp, -1, sizeof(dp[0][0]) * 2005*2005);
	loop(i,n+1)	dp[i][0]=0;
	int res = 0;

	for(int i=1; i<=n; i++) {
		for(int k=1; k<=i; k++) {
			if(dp[i-1][k-1]!=-1 && dp[i-1][k-1] + arr[i] >=0 ) {
				dp[i][k]=max(dp[i-1][k-1] + arr[i], dp[i-1][k]);
			} else {
				dp[i][k] = dp[i-1][k];
			}
			if(dp[i][k]!=-1)	res = max(res, k);
		}
	}
  for(int i=0; i<=n;i++) {
		cout<<"i value"<<i<<"\n";
		for(int j=0; j<=n; j++) {
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n\n\n";
	}
	cout<<res<<"\n";
	return 0;
}
