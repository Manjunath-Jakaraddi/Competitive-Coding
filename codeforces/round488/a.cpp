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
int arr[20];
unordered_map<int,int> mmap;
int main()
{
	prep();
  int n,m;
  cin>>n>>m;
  loop(i,n) cin>>arr[i];
  int x;
  loop(i,m)
  {
    cin>>x;
    mmap[x]=1;
  }
  loop(i,n)
    if(mmap[arr[i]])  cout<<arr[i]<<" ";
	return 0;
}
