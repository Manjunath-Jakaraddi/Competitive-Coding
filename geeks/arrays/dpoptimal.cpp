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
int n;
int arr[1000];
int solve(int i,int j)
{
  if(j<i) return 0;
  if(i==j)  return arr[i];
  return max(arr[i]+min(solve(i+1,j-1),solve(i+2,j)),
              arr[j]+min(solve(i+1,j-1),solve(i,j-2)));
}
int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i];
  cout<<solve(0,n-1)<<" ";
	return 0;
}
