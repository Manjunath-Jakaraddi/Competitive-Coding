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
int main()
{
	prep();
  int N,E,wt,x,y;
  cin>>N>>E;
  int dist[N][E];
  rep(i,0,N)
    rep(j,0,N)
      dist[i][j]=999;
  loop(i,E)
  {
    cin>>x>>y>>wt;
    x--;
    y--;
    dist[x][y]=dist[y][x]=wt;
  }
  loop(k,N)
    loop(i,N)
      loop(j,N)
        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
  return 0;
}
