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
int arr[100005],tmp[100005],take[100005];
unordered_map<int,int> mmap;
int main()
{
  prep();
  int n,m,d;
  cin>>n>>m>>d;
  loop(i,m)
  {
    cin>>arr[i+1];
    tmp[i+1]=arr[i+1];
    mmap[arr[i+1]]=i+1;
  }
  sort(tmp+1,tmp+m+1);
  rep(i,1,n)    take[mmap[tmp[i]]]=1;
  rep(i,1,m)  if(take[i])  cout<<arr[i]<<" ";
  return 0;
}
