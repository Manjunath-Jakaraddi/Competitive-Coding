// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef vector<int> vi;
// #define MOD 1000000007
// #define pb push_back
// #define pf printf
// #define sf scanf
// #define all(v) v.begin(), v.end()
// #define rep(i, s, e) for(auto i=s; i<e; i++)
// #define loop(i, n) for(int i=0; i<n; i++)
// #define mp make_pair
// inline void prep()
// {
// 	cin.tie(0);
// 	cin.sync_with_stdio(0);
// }
// vector<pair<ll,ii>> eprs;
// vi dist;
// int main()
// {
// 	prep();
//   int n,e,x,y,wt;
//   cin>>n>>e;
//   dist.assign(n+1,INT_MAX);
//   loop(i,e)
//   {
//     cin>>x>>y>>wt;
//     eprs.pb({wt,{x,y}});
//   }
//   dist[1]=0;
//   loop(i,n-1)
//   {
//     loop(j,eprs.size())
//     {
//       int frm=eprs[j].second.first,to=eprs[j].second.second;
//       ll w=eprs[j].first;
//       if(dist[to]>dist[frm]+w)
//         dist[to]=dist[frm]+w;
//     }
//   }
//   loop(i,n-1)
//   if(dist[i+2]==INT_MAX)  cout<<"  ";
//   else  cout<<dist[i+2]<<" ";
//   cout<<"\n";
//   //To Check For Negative Cycles
//   loop(j,eprs.size())
//   {
//     int frm=eprs[j].second.first,to=eprs[j].second.second;
//     ll w=eprs[j].first;
//     if(dist[to]>dist[frm]+w)
//     {
//       cout<<"Negative Weight Cycle\n";
//       break;
//     }
//   }
//   return 0;
// }
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
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int V,E,x,y,wt;
vi dist;
vector<vii> edges;
int main()
{
	prep();
	cin>>V>>E;
	dist.assign(V,INT_MAX);edges.assign(V,vii());
	loop(i,E)
	{
		cin>>x>>y>>wt;
		edges[x].pb({y,wt});
	}
	dist[0]=0;//dist[source]=0 SSSP
	loop(i,V-1)
		rep(s,0,V)
			for(auto it:edges[s])
			{
				int frm=s,to=it.first,wt=it.second;
				dist[to]=min(dist[to],dist[frm]+wt);
			}
	loop(i,V)	cout<<((dist[i]==INT_MAX)?-1:dist[i])<<" ";
	return 0;
}
