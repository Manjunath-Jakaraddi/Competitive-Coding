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
int dx[8]={-1,1,0,0};
int dy[8]={0,0,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int m,n;
string grid[505];
bool isValid(int x, int y) {
  return (x>=0 && x<m && y>=0 && y<n);
}
bool isWolfPresent(int x, int y) {
  loop(i,4) {
    if(isValid(x+dx[i], y+dy[i]) && grid[x+dx[i]][y+dy[i]] == 'W') {
      return true;
    }
  }
  return false;
}

int main()
{
	prep();
  cin>>m>>n;
  loop(i,m) cin>>grid[i];
  loop(i,m) {
    loop(j,n) {
      if(grid[i][j] == 'S' && isWolfPresent(i,j)) {
        cout<<"No\n";
        return 0;
      }
    }
  }
  cout<<"Yes\n";
  loop(x,m) {
    loop(y,n) {
      if(grid[x][y] == '.') {
        grid[x][y]='D';
      }
    }
  }
  loop(i, m) cout<<grid[i]<<"\n";
	return 0;
}
