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
int n,d;
int arr[200];
int main()
{
	prep();
  cin>>n>>d;
  loop(i,n) cin>>arr[i];
  sort(arr,arr+n);
  int cnt=2;
  for(int i=1;i<n;i++)
  {
    if(arr[i]-arr[i-1]==2*d)
    cnt++;
    else if(arr[i]-arr[i-1]>2*d)
    cnt+=2;
  }
  cout<<cnt<<"\n";
  return 0;
}
