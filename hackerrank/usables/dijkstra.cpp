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
class dijkstra
{
    vi dist;
    vector<vii> edges;
    int N,E;
  public:
    dijkstra(int n,int e)
    {
      // cout<<n<<" "<<e<<"\n";
      this->N=n;
      this->E=e;
      edges.assign(n,vii());
      dist.assign(n,INT_MAX);
    }
    void read()
    {
      int wt,x,y;
      // cout<<N<<" "<<E<<"\n";
      loop(i,E)
      {
        cin>>x>>y>>wt;
        x--;y--;
        edges[x].pb({wt,y});
        // edges[y].pb({wt,x});
      }
    }
    void run(int s)
    {
      multiset<ii> pq;//Min priority Queue
      dist[s]=0;
      pq.insert({0,s});
      while(!pq.empty())
      {
				cout<<"!";
        ii z=*pq.begin();pq.erase(pq.begin());
        int frm=z.second,wei=z.first;
        if(wei>dist[frm])  continue; //Lazy deletion
        // cout<<frm<<"-->";
        for(auto it:edges[frm])
        {
          int to=it.second,wt=it.first;
          if(dist[to]>dist[frm]+wt)
          {
            dist[to]=dist[frm]+wt;
            pq.insert({dist[to],to});
          }
        }
      }
    }
    void printdist()
    {
      rep(i,1,N-1) cout<<dist[i]<<" ";
    }
};
int main()
{
	prep();
  int n,e;
  cin>>n>>e;
  dijkstra dk(n,e);
  dk.read();
  dk.run(0);
  dk.printdist();
	return 0;
}
