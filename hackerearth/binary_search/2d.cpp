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
int dx[7]={-1,1,0,-1,-1,1,1};
int dy[7]={0,0,0,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int arr[10][10];
int main()
{
	prep();
  int n=6,m=6;
  loop(i,n) loop(j,n) cin>>arr[i][j];
  int ans=0;
  for(int i=1;i<5;i++)  for(int j=1;j<5;j++)
  {
    int cnt=0;
    for(int k=0;k<7;k++)   cnt+=(arr[i+dx[k]][j+dy[k]]);
    ans=max(ans,cnt);
  }
  cout<<ans<<"\n";
	return 0;
}
