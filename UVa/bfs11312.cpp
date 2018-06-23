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
int dist[10000007];
int main()
{
	prep();
  int t,l,n,r,tr;
  cin>>t;
  while(t--)
  {
    cin>>n>>l>>r>>tr;
    queue<int> q;
    rep(i,1,n)  dist[i]=INT_MAX;
    q.push(1);
    dist[1]=0;
    while(!q.empty())
    {
      int z=q.front();q.pop();
      if(z-l>0&&dist[z-l]>dist[z]+1)
      {
        q.push(z-l);
        dist[z-l]=dist[z]+1;
        if(z-l==tr) break;
      }
      if(z+r<=n&&dist[z+r]>dist[z]+1)
      {
        q.push(z+r);
        dist[z+r]=dist[z]+1;
        if(z+r==tr) break;
      }
    }
    if(dist[tr]==INT_MAX) cout<<"uh-oh!\n";
    else  cout<<dist[tr]<<"\n";
  }
  return 0;
}
