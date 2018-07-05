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
int n,q,x;
int arr[200005];
int has[40];
int solve()
{
  int res=0;
  int tmphas[40];
  for(int i=0;i<40;i++) tmphas[i]=has[i];
  for(int i=31;i>=0;i--)
  {
    if(((x>>i)&1)&&tmphas[i])
    {
      tmphas[i]--;
      res++;
    }
    else if(((x>>i)&1)&&!tmphas[i])
    {
      bool ok=false,reqd=2;
      for(int c=i-1;c>=0;c--)
      {
        if(tmphas[c]-reqd>=0)
        {
          tmphas[c]-=reqd;
          res+=reqd;
          ok=true;
          break;
        }
        
        reqd<<=1;
      }
      if(!ok)
        return -1;
    }
  }
  return res;
}
int main()
{
	prep();
  cin>>n>>q;
  // loop(i,n)
  // {
  //   cin>>arr[i];
  //   has[(int)log2(arr[i])]++;
  // }
  has[0]=200000;
  while(q--)
  {
    cin>>x;
    cout<<solve()<<"\n";
  }
	return 0;
}
