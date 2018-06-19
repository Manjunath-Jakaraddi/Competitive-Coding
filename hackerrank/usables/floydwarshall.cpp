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

int N,E,wt,x,y;
int dist[100][100],par[100][100],is_connected[100][100],minimax[100][100];
void printshortestpath(int,int);
int main()
{
	prep();
  cin>>N>>E;
  rep(i,0,N)
    rep(j,0,N)
      dist[i][j]=minimax[i][j]=999,par[i][j]=i;;
  loop(i,E)
  {
    cin>>x>>y>>wt;
    // x--;
    // y--;
    dist[x][y]=wt;
		minimax[x][y]=wt;
		is_connected[x][y]=1;
		// dist[y][x]=wt;
  }
	loop(i,N)
	{
		loop(j,N)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
  loop(k,N)
    loop(i,N)
      loop(j,N)
			{
				is_connected[i][j]|=(is_connected[i][k]&is_connected[k][j]);
				minimax[i][j]=min(minimax[i][j],max(minimax[i][k],minimax[k][j]));
				// dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
				if(dist[i][j]>dist[i][k]+dist[k][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
					par[i][j]=par[k][j];
				}
			}
	if(is_connected[3][4])	cout<<"Yes connected\n";
	else	cout<<"Not connected\n";
	printshortestpath(3,4);
  return 0;
}
void printshortestpath(int i,int j)
{
	if(i!=j)	 printshortestpath(i,par[i][j]);
	cout<<j<<" ";
}
