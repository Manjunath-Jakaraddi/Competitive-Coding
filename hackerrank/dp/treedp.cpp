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
int n,cnt,K,root,x;
vector<vi> edges;
vi reward,inv,jump;
void dfs(int i)
{
  int pre=cnt++;
  inv[pre]=i;
  for(auto it:edges[i])
    dfs(it);
  jump[pre]=cnt;
}
int main()
{
	prep();
  cin>>n>>K;
  root=-1;
  reward.assign(n,0);
  inv.assign(n,0);
  jump.assign(n,0);
  edges.assign(n,vi());
  loop(i,n)
  {
    cin>>x;
    x--;
    if(x==-1) root=i;
    else  edges[x].pb(i);
    cin>>reward[i];
  }
  dfs(root);
  vi cur(n+1,INT_MIN);
  cur[0]=0;
  for(int k=0;k<K;k++)
  {
    vi nxt(n+1,INT_MIN);
    for(int i=0;i<n;i++)
    {
      // state- (i,k)
      // i - ith node preorder number
      // k taken k nodes
      // (i,k) -> (i+1,k)
      cur[i+1]=max(cur[i+1],cur[i]);
      // (i,k) -> (jump[i],k+1)
      nxt[jump[i]]=max(nxt[jump[i]],cur[i]+reward[inv[i]]);
    }
    for(int i=0;i<=n;i++) cur[i]=nxt[i];
  }
  int res=0;
  for(auto it:cur)  res=max(res,it);
  cout<<res<<"\n";
  return 0;
}
