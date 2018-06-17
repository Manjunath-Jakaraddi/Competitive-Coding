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
// #define rep(i, s, e) for(auto i=s; i<=e; i++)
// #define loop(i, n) for(int i=0; i<n; i++)
// #define oo 987654321
// int dx[8]={-1,1,0,0,-1,-1,1,1};
// int dy[8]={0,0,-1,1,-1,1,-1,1};
// inline void prep()
// {
// 	cin.tie(0);
// 	cin.sync_with_stdio(0);
// }
// int n,m,x,y,clks,numscc=-1;
// vi vis,disc,lowlink;
// vector<vi> scc;
// vector<vi> edges;
// stack<int> st;
// void findSCC(int s)
// {
//   clks++;
//   vis[s]=1;
//   disc[s]=lowlink[s]=clks;
//   st.push(s);
//   for(auto it:edges[s])
//   {
//     // Forward Edge
//     if(!vis[it])  findSCC(it);
//     //Forward Backward and Cross
//     lowlink[s]=min(lowlink[s],lowlink[it]);
//   }
//   if(lowlink[s]==disc[s])
//   {
//     numscc++;
//     scc.pb(vi());
//     while(1)
//     {
//       int ele=st.top();
//       scc[numscc].pb(ele);
//       lowlink[ele]=oo; // update to oo so that ignores the cross edges
//       // while updating the lowink values
//       st.pop();
//       if(s==ele)  break;
//     }
//   }
// }
// int main()
// {
// 	prep();
//   cin>>n>>m;
//   vis.assign(n,0);disc.assign(n,0);lowlink.assign(n,0);edges.assign(n,vi());
//   loop(i,m)
//   {
//     cin>>x>>y;
//     x--;y--;
//     edges[x].pb(y);
//   }
//   loop(i,n) if(!vis[i]) findSCC(i);
//   int res=0;
//   loop(i,scc.size())
//     if(scc[i].size()&1) res+=scc[i].size();
//     else  res-=scc[i].size();
//   cout<<res<<"\n";
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
#define UNVISITED 0
int n,m,x,y;
int dfs_counter,numSCC;
vi dfs_num,dfs_low,st;
vector<vi> edges;
void tarjanSCC(int s)
{
	dfs_num[s]=dfs_low[s]=++dfs_counter;
	st.pb(s);
	for(auto it:edges[s])
	{
		if(dfs_num[it]==UNVISITED)
			tarjanSCC(it);
		// For all Tree Back Cross Edges
		dfs_low[s]=min(dfs_low[s],dfs_low[it]);
	}
	if(dfs_num[s]==dfs_low[s])
	{
		cout<<"SCC "<<++numSCC<<": \nRoot of SCC : "<<s<<"\n\t";
		while(1)
		{
			int ele=st.back();st.pop_back();
			dfs_low[ele]=n;//To Ignore the Cross edges while updating dfs_low in future
			cout<<ele<<" ";
			if(ele==s)	break;
		}
		cout<<"\n";
	}
}
int main()
{
	prep();
	cin>>n>>m;
	dfs_num.assign(n,0);
	dfs_low.assign(n,0);
	edges.assign(n,vi());
	loop(i,m)
	{
		cin>>x>>y;
		edges[x].pb(y);
	}
	loop(i,n)	if(dfs_num[i]==UNVISITED)	tarjanSCC(i);
	return 0;
}
