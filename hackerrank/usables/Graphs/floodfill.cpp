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
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int grid[10],vis[10];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
int n,m,x;
bool reach(int x,int y)
{
  if(x==(n-1)&&(y==m-1))  return true;
  if(x<0||x>=n||y<0||y>=m)  return false;
  if(vis[x]&(1<<(m-y-1))) return false;
  if(!(grid[x]&(1<<(m-y-1)))) return false;
  vis[x]|=(1<<(m-y-1));
  loop(k,4) if(reach(x+dx[k],y+dy[k]))  return true;
  return false;
}
int main()
{
	prep();
  cin>>n>>m;
  loop(i,n)
    loop(j,m)
    {
      cin>>x;
      grid[i]=(grid[i]|((1<<(m-j-1))*x));
    }
  if(reach(0,0))  cout<<"Yes\n";
  else  cout<<"No\n";
	return 0;
}
