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
int dx[8]={0,1,0,-1,-1,-1,1,1};
int dy[8]={1,0,-1,0,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int n,m;
int mat[200][200];
int main()
{
	prep();
  cin>>n>>m;
  int x=1,y=1,cnt=0,dir=0;
  loop(i,n) loop(j,m) cin>>mat[i+1][j+1];
  while(cnt<(n*m))
  {
    cout<<mat[x][y]<<" ";
    cnt++;
    mat[x][y]=0;
    loop(i,4)
    {
      int nx=x+dx[dir],ny=y+dy[dir];
      if(nx>0&&nx<=n&&ny>0&&ny<=m&&mat[nx][ny])
      {
        x=nx,y=ny;
        break;
      }
      dir=(dir+1)%4;
    }
  }
	return 0;
}
