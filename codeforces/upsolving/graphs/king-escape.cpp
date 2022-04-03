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
int n;
int qx, qy, kx, ky, fx, fy;
// bool isValid(int x, int y) {
//   if(x>0 && x<=n && y>0 && y<=n) {
//     if(x==qx || y==qy) return false;
//     if(abs(qx-x) == abs(qy-y)) return false;
//     return true;
//   }
//   return false;
// }
int main()
{
	prep();
  cin>>n;
  cin>>qx>>qy>>kx>>ky>>fx>>fy;
  // if(!isValid(kx, ky) || !isValid(fx, fy)) {
  //   cout<<"NO\n";
  //   return 0;
  // }
  // queue<ii> q;
  // q.push({kx, ky});
  // map<ii, int> vis;
  // vis[{kx,ky}]=1;
  // while(!q.empty()) {
  //   int cx = q.front().first, cy = q.front().second;
  //   q.pop();
  //   loop(i,8) {
  //     int nx=cx+dx[i], ny=cy+dy[i];
  //     if(isValid(nx,ny) && !vis[{nx,ny}]) {
  //       if(nx==fx && ny == fy) {
  //         cout<<"YES\n";
  //         return 0;
  //       }
  //       vis[{nx, ny}]=1;
  //       q.push({nx, ny});
  //     }
  //   }
  // }
  // cout<<"NO\n";
  kx-=qx;ky-=qy;fx-=qx;fy-=qy;
  if(kx*fx > 0 && ky*fy>0) cout<<"YES\n";
  else cout<<"NO\n";
	return 0;
}
