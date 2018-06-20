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
ll t,n,k;

int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    ll res[1000]={0};
    cin>>n>>k;
    loop(i,min(n,k)) res[i]=1;
    if(n>k)
    {
      n-=k;//3
      int dv=(n/(k-1));//1
      int md=(n%(k-1));//1
      if(dv&1)
      {
        loop(i,m)
        {
          if(!i)
          {
            
          }
          else if(i!=m-1)
          {
            cout<<dv+md<<" ";
            md--;
          }
          else
            cout<<dv<<" ";
        }
        cout<<"\n";
      }
    }
  }
	return 0;
}
