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
int main()
{
	prep();
  int t,n,l,r,x,m,k;
  cin>>t;
  while(t--)
  {
    cin>>m>>k;
    map<int,int> arr;
    loop(i,m)
    {
      cin>>l>>r>>x;
      arr[l]+=x;
      arr[r+1]-=x;
    }
    ll sm=0,ans=0;
    for(auto it:arr)
    {

    }
    loop(i,13)  cout<<arr[i]<<" ";
    cout<<ans<<"\n";
  }
  return 0;
}
