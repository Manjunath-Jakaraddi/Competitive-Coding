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
int nextnum(int i)
{
  i|=i>>1;
  i|=i>>2;
  i|=i>>4;
  i|=i>>8;
  i|=i>>16;
  return (i+1);
}
int n,x;
vi arr,valid,idx;
vii eprs;
int main()
{
	prep();
  cin>>n;
  valid.assign(n,0);
  arr.assign(n,0);
  idx.assign(n,0);
  loop(i,n)
  {
    cin>>x;
    eprs.pb({x,i});
  }
  sort(all(eprs));
  loop(i,n)
  {
    arr[i]=eprs[i].first;
    idx[i]=eprs[i].second;
  }
  loop(i,n)
  {
    if(!valid[i])
    {
      // cout<<arr[i]<<" "<<nextnum(arr[i])<<"\n";
      int s=lower_bound(all(arr),nextnum(arr[i])-arr[i])-arr.begin();
      int e=upper_bound(all(arr),nextnum(arr[i])-arr[i])-arr.begin();
      bool ok=false;
      for(int j=s;j<e;j++) if(i!=idx[j])
      {
        ok=true;
        valid[j]=1;
      }
      if(ok)  valid[i]=1;
    }
  }
  int res=0;
  loop(i,n) if(!valid[i])
  {
    cout<<arr[i]<<" ";
    res++;
  }
  cout<<res<<"\n";
	return 0;
}
