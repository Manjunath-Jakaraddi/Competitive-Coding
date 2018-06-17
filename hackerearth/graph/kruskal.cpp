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
#define rep(i, s, e) for(auto i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int N,E,x,y,wt;
class kruskal
{
  vi pr,rnk;
	int cost=0;
  vector<pair<ll,ii> > edges;
  public:
    kruskal(int n)
    {
      pr.assign(n+1,0);
			rnk.assign(n+1,0);
      loop(i,n+1)  pr[i]=i;
    }
    void insert_edge(int wt,int x,int y)
    {
      edges.pb({wt,{x,y}});
    }
		int findSet(int i)
		{
			return (pr[i]==i)?i:(pr[i]=findSet(pr[i]));
		}
		int isSameSet(int i,int j)
		{
			return (findSet(i)==findSet(j));
		}
		int unionSet(int i,int j)
		{
			int x=findSet(i),y=findSet(j);
			if(rnk[x]>rnk[y])	pr[y]=x;
			else
			{
				pr[x]=y;
				if(rnk[x]==rnk[y])	rnk[y]++;
			}
		}
		int run()
		{
			sort(all(edges));
			loop(i,edges.size())
			{
				int x=edges[i].second.first;
				int y=edges[i].second.second;
				if(!isSameSet(x,y))
				{
					cost+=edges[i].first;
					unionSet(x,y);
				}
			}
			return cost;
		}
};
int main()
{
	prep();
  cin>>N>>E;
  kruskal kr(N);
  loop(i,E)
	{
		cin>>x>>y>>wt;
		kr.insert_edge(wt,x,y);
	}
	cout<<kr.run()<<"\n";
  return 0;
}
