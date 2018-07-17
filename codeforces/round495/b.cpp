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
int n,m,l,r;
int arr[1005];
int main()
{
	prep();
  cin>>n>>m;
  loop(i,m)
  {
    cin>>l>>r;
    for(int j=l;j<=r;j++) arr[j]++;
  }
  int i=1,tog=0;
  // rep(i,1,n)  cout<<arr[i]<<" ";  cout<<"\n";
  while(i<n)
  {
    int cnt=1;
    while(i<n&&arr[i]==arr[i+1])  cnt++,i++;
    // cout<<cnt<<" "<<i<<"!\n";
    if(cnt==1)
    {
      // cout<<arr[i]<<"\n";
      cout<<tog;
      tog=1-tog;
      i++;
      continue;
    }
    for(int j=0;j<ceil((double)cnt/2);j++) cout<<"1";
    for(int j=0;j<cnt/2;j++)  cout<<"0";
  }
	return 0;
}
