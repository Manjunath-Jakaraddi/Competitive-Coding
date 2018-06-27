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
int n,q,k;
int arr[100005],cntbits[100005];
int solve(int k)
{
  int res=INT_MAX;
  int l=0,r=0,cntk=0;
  while(l<r&&r<n)
  {
    if(cntk<k) cntk+=cntbits[r++];
    else
    {
      if(l>r) break;
      res=min(res,r-l);
      cntk-=cntbits[l++];
    }
  }
  while(l<r)
  {
    if(cntk>=k)
    {
      res=min(res,r-l);
      cntk-=cntbits[l++];
    }
    else
      break;
  }
  return res;
}
int main()
{
	prep();
  cin>>n>>q;
  loop(i,n)
  {
    cin>>arr[i];
    cntbits[i]=__builtin_popcount(arr[i]);
  }
  while(q--)
  {
    cin>>k;
    int res=solve(k);
    cout<<(res==INT_MAX?-1:res)<<"\n";
  }
	return 0;
}
