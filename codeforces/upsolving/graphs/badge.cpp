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
int dfs(int curr, int vis[], int par[]) {
  vis[curr]=1;
  if(!vis[par[curr]]) {
    return dfs(par[curr], vis, par);
  }
  return par[curr];
}

int findParentInCycle(int curr, int par[], int res[]) {
  return (curr == res[curr]? curr : res[curr]=findParentInCycle(par[curr], par, res));
}
int main()
{
	prep();
  int n;
  cin>>n;
  int par[n+1];
  // loop(i,n) {
  //   int vis[n+1];
  //   memset(vis, 0, sizeof(vis));
  //   cout<<dfs(i+1, vis, par)<<" ";
  // }
  // cout<<"\n";

  int indeg[n+1];
  memset(indeg, 0, sizeof(indeg));
  loop(i,n) {
    cin>>par[i+1];
    indeg[par[i+1]]++;
  }
  int res[n+1];
  queue<int> q;
  loop(i, n) {
    res[i+1]=i+1;
    if(!indeg[i+1]) q.push(i+1);
  }
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    --indeg[par[curr]];
    res[curr]=par[curr];
    if(!indeg[par[curr]]) q.push(par[curr]);
  }
  loop(i,n) cout<<findParentInCycle(i+1, par, res)<<" ";
  cout<<"\n";
  return 0;
}
