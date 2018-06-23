  #include<bits/stdc++.h>
  using namespace std;
  typedef long long ll;
  typedef pair<ll, ll> ii;
  typedef vector<ii> vii;
  typedef vector<ll> vi;
  #define MOD 1000000007
  #define pb push_back
  #define pf prllf
  #define sf scanf
  #define all(v) v.begin(), v.end()
  #define rep(i, s, e) for(auto i=s; i<=e; i++)
  #define loop(i, n) for(ll i=0; i<n; i++)
  #define oo 987654321
  ll dx[8]={-1,1,0,0,-1,-1,1,1};
  ll dy[8]={0,0,-1,1,-1,1,-1,1};
  inline void prep()
  {
  	cin.tie(0);
  	cin.sync_with_stdio(0);
  }
  ll N,D,x,y,wt;
  vector<vector<pair<ll,int> > > tree;//wt ind
  vector<vector<ll> > dist_root;
  vector<ll> dist;
  void bfs(int s)
  {
    queue<int> q;
    vi depth;
    depth.assign(N,INT_MAX);
    q.push(s); // ind wt
    dist_root[s][s]=0;
    depth[s]=0;
    while(!q.empty())
    {
      ll z=q.front();q.pop();
      for(auto it:tree[z])  if(depth[it.second]>depth[z]+1)
      {
        dist_root[s][it.second]=dist_root[s][z]+it.first;
        depth[it.second]=depth[z]+1;
        q.push(it.second);
      }
    }
  }
  int main()
  {
  	prep();
    cin>>N;
    tree.assign(N,vector<pair<ll,int> >());
    loop(i,N-1)
    {
      cin>>x>>y>>wt;
      x--;y--;
      tree[x].pb({wt,y});
      tree[y].pb({wt,x});
    }
    dist_root.assign(N,vector<ll>(N,LLONG_MAX));
    dist.assign(N,LLONG_MAX);
    loop(i,N) bfs(i);
    // loop(i,N)  loop(j,N)  cout<<dist_root[i][j]<<(j==N-1?"\n":" ");
    dist[0]=0;
    for(ll i=0;i<N-1;i++)
      for(ll j=i+1;j<N;j++)
        dist[j]=min(dist[j],dist[i]+dist_root[i][j]);
    loop(i,N) cout<<dist[i]<<" ";
    return 0;
  }
