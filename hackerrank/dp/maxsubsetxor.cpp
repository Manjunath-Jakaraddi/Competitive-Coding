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
vi arr;
int n;
int maxsubsetxor()
{
  int ind=0;
  for(int i=31;i>=0;i--)
  {
    int maxEle=INT_MIN,mxind=0;
    for(int j=ind;j<n;j++)
    {
      if((1<<i)&arr[j])
      {
        maxEle=arr[j];
        mxind=j;
      }
    }
    if(maxEle==INT_MIN) continue;
    swap(arr[mxind],arr[ind]);
    mxind=ind;
    for(int j=0;j<n;j++)
      if(((1<<i)&arr[j])&&j!=mxind) arr[j]^=maxEle;
    ind++;
  }
  int res=0;
  loop(i,n) res^=arr[i];
  return res;
}
int main()
{
	prep();
  cin>>n;
  arr.assign(n,0);
  loop(i,n)  cin>>arr[i];
  cout<<maxsubsetxor()<<"\n";
	return 0;
}
