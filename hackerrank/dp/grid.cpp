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
string grid[4];
bool isValid(int x,int y)
{
    return x>=0&&x<4&&y>=0&&y<4;
}
bool solve(int x,int y)
{
    loop(i,8)
    {
        vector<char> cnt;
        loop(j,3)
        {
          int nx=x+j*dx[i],ny=y+j*dy[i];
          if(isValid(nx,ny))  cnt.pb(grid[nx][ny]);
        }
        if(cnt.size()>=2)
          if(count(all(cnt),'x')==2&&count(all(cnt),'.')==1)  return true;
    }
    return false;
}
int main()
{
	prep();
	int t;
	cin>>t;
	while(t--)
	{
	    loop(i,4)   cin>>grid[i];
	    bool ok=false;
	    loop(i,4)
	    {
	        loop(j,4)
    	    {
    	        if(grid[i][j]=='x')
    	         {
    	             if(solve(i,j))
    	             {
    	                 cout<<"YES\n";
    	                 ok=true;
    	                 break;
    	             }
    	         }
    	    }
    	    if(ok)  break;
	    }
	    if(!ok) cout<<"NO\n";
	}
	return 0;
}
