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
int dist[11][11],grid[11][11],t,n,m,last;
int main()
{
    prep();
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        loop(i,n)   loop(j,m)   cin>>grid[i][j];
        cout<<"\n\n";
        if(grid[0][0]<0)  dist[0][0]=grid[0][0];
        loop(i,n)   loop(j,m)   cout<<grid[i][j]<<(j==m-1?"\n":" ");
        loop(i,m)   if(i)
        {
            grid[0][i]+=grid[0][i-1];
            dist[0][i]=min(dist[0][i-1],grid[0][i]);
        }
        loop(i,n)   if(i)
        {
            grid[i][0]+=grid[i-1][0];
            dist[i][0]=min(dist[i-1][0],grid[i][0]);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(grid[i-1][j]>grid[i][j-1])
                {
                    grid[i][j]+=grid[i-1][j];
                    dist[i][j]=min(dist[i-1][j],grid[i][j]);
                }
                else
                {
                    grid[i][j]+=grid[i][j-1];
                    dist[i][j]=min(dist[i][j-1],grid[i][j]);
                }
            }
        }
        cout<<"\n\n";
        loop(i,n)   loop(j,m)   cout<<grid[i][j]<<(j==m-1?"\n":" ");
        cout<<"\n\n";
        loop(i,n)   loop(j,m)   cout<<dist[i][j]<<(j==m-1?"\n":" ");
        cout<<abs(dist[n-1][m-1])<<"\n";
        loop(i,n)   loop(j,m)
        {
            grid[i][j]=0;
            dist[i][j]=0;
        }
    }
    return 0;
}
