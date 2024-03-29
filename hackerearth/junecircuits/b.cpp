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
bool rect(int x,int y,int z)
{
  int arr[3]={x,y,z};
  sort(arr,arr+3);
  if(arr[2]<=arr[1]+arr[0])  return true;
  return false;
}
int n;
ll arr[200005],dp[200005];
int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i+1];
	dp[1]=1;
  for(int i=2;i<=n;i++)
  {
		dp[i]=(2+dp[i-1]);
		if(i>2)	dp[i]+=(rect(arr[i],arr[i-1],arr[i-2]));
	}
	cout<<dp[n]<<"\n";
  return 0;
}
