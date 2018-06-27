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
int arr[100005];
int main()
{
	prep();
  cin>>n;
  int mn=INT_MAX;
  loop(i,n)
  {
    cin>>arr[i];
    mn=min(mn,arr[i]);
  }
  int idx=-1;
  loop(i,n)
  {
    arr[i]-=mn;
  }
  mn%=n;
  for(int i=0;i<n;i++)
  {
    if(arr[(mn+i)%n]-i<=0)
    {
      // cout<<arr[(idx+i)%n]<<" ";
      cout<<(mn+i)%n+1<<"\n";
      break;
    }
  }
	return 0;
}
