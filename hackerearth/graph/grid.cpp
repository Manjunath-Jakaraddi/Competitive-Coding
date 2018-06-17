#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define oo 987654321
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
int n,m,q,x,y,s;
string grid[1001];
int dist[1001][1001],vis[1001][1001];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int x,int y)
{
  return (x>=0&&x<n&&y>=0&&y<m&&grid[x][y]=='O');
}
void solve(int sx,int sy)
{
  loop(i,1001)  loop(j,1001)  dist[i][j]=oo;
  dist[sx][sy]=0;
  multiset<pair<int,ii> > pq;
  pq.insert({0,{sx,sy}});
  while(!pq.empty())
  {
    pair<int,ii> z=*pq.begin();pq.erase(pq.begin());
    int frmx=z.second.first,frmy=z.second.second;
    if(vis[frmx][frmy]) continue;
    vis[frmx][frmy]=1;
    loop(i,4)
    {
      int tox=frmx+dir[i][0],toy=frmy+dir[i][1];
      if(valid(tox,toy)&&dist[tox][toy]>dist[frmx][frmy]+1)
      {
        dist[tox][toy]=dist[frmx][frmy]+1;
        pq.insert({dist[tox][toy],{tox,toy}});
      }
    }
  }
}
int main()
{
	prep();
  cin>>n>>m>>q;
  loop(i,n) cin>>grid[i];
  cin>>x>>y;
  x--;y--;
  solve(x,y);
  while(q--)
  {
    cin>>x>>y;
    x--;y--;
    cout<<((dist[x][y]==oo)?-1:dist[x][y])<<"\n";
  }
	return 0;
}
