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
int n,sx,sy,dtx,dty;
string grid[105];
int dist[105][105][4];
bool isValid(int x,int y)
{
  return (x>=0&&x<n&&y>=0&&y<n&&grid[x][y]!='X');
}
void bfs()
{
  queue<pair<int,ii>> q;
  loop(k,4)
  {
    q.push({k,{sx,sy}});
    dist[sx][sy][k]=0;
  }
  while(!q.empty())
  {
    int frmx=q.front().second.first,frmy=q.front().second.second,dir=q.front().first;q.pop();
    loop(i,4)
    {
      int tox=frmx+dx[i],toy=frmy+dy[i];
      if(isValid(tox,toy)&&dist[tox][toy][i]>dist[frmx][frmy][dir]+(dir!=i))
      {
        dist[tox][toy][i]=dist[frmx][frmy][dir]+(i!=dir);
        q.push({i,{tox,toy}});
      }
    }
  }
  int ans=INT_MAX;
  loop(k,4) ans=min(ans,dist[dtx][dty][k]);
  cout<<ans+1<<"\n";
}
int main()
{
	prep();
  cin>>n;
  loop(i,n+1) loop(j,n+1) loop(k,4) dist[i][j][k]=INT_MAX;
  loop(i,n)   cin>>grid[i];
  cin>>sx>>sy>>dtx>>dty;
  bfs();
	return 0;
}
