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
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vector<ii> arr(n);
    loop(i, n) {
      cin>>arr[i].first;
      arr[i].second=i+1;
    }
    sort(all(arr));
    loop(i, n) {
      cout<<arr[i].first<<" : "<<arr[i].second<<"\n";
    }
    if(arr[0].first!=arr[1].first) 
    loop(i,n-1) {
      if(arr[i].first != arr[i+1].first) {
        cout<<arr[i].second<<"\n";
        found=true;
        break;
      }
    }
    if(!found)  cout<<"-1\n";
  }
	return 0;
}
