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
// #define mp make_pair
// inline void prep()
// {
// 	cin.tie(0);
// 	cin.sync_with_stdio(0);
// }
// int n,m,sx,sy,dx,dy;
// int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
// string s[1003];
// vector<vi> mndir(1003,vi(1003,INT_MAX));
// vector<vi> vis(1003,vi(1003,0));
// bool isvalid(int x,int y)
// {
//   return (x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='*');
// }
// void solve(int x,int y)
// {
//   multiset<pair<int,ii> > pq;
//   mndir[x][y]=0;
//   pq.insert({0,{x,y}});
//   while(!pq.empty())
//   {
//     pair<int,ii> z=*pq.begin();
//     int frmx=z.second.first,frmy=z.second.second;
//     int mncost=z.first;
//     pq.erase(pq.begin());
//     if(vis[frmx][frmy]) continue;
//     vis[frmx][frmy]=1;
//     for(int i=0;i<4;i++)
//     {
//       int tox=frmx+dir[i][0],toy=frmy+dir[i][1];
//       int tmpx=frmx,tmpy=frmy;
//       while(isvalid(tox,toy))
//       {
//         if(mndir[tox][toy]>mncost)
//         {
//           mndir[tox][toy]=mncost;
//           pq.insert({mncost+1,{tox,toy}});
//         }
//         tmpx=tox;
//         tmpy=toy;
//         tox=tmpx+dir[i][0],toy=tmpy+dir[i][1];
//       }
//     }
//   }
// }
// int main()
// {
// 	prep();
//   cin>>n>>m;
//   loop(i,n)
//   {
//     cin>>s[i];
//     loop(j,m)
//     {
//       if(s[i][j]=='V')  sx=i,sy=j;
//       else if(s[i][j]=='H') dx=i,dy=j;
//     }
//   }
//   solve(sx,sy);
//   cout<<((mndir[dx][dy]==INT_MAX)?-1:mndir[dx][dy])<<"\n";
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
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int n,m,sx,sy,dtx,dty;
string s[1003];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int dist[1003][1003][4];
bool isValid(int x,int y)
{
	return (x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='*');
}
void solve()
{
		queue<pair<int,ii>> pq;
		loop(i,4)
		{
			pq.push({i,{sx,sy}});
			dist[sx][sy][i]=0;
		}
		while(!pq.empty())
		{
			pair<int,ii> z=pq.front();pq.pop();
			int frmx=z.second.first,frmy=z.second.second,dir=z.first;
			loop(i,4)
			{
				int tox=frmx+dx[i],toy=frmy+dy[i];
				if(isValid(tox,toy)&&dist[tox][toy][i]>dist[frmx][frmy][dir]+(dir!=i))
				{
					dist[tox][toy][i]=dist[frmx][frmy][dir]+(dir!=i);
					pq.push({i,{tox,toy}});
				}
			}
		}
}
int main()
{
	prep();
  cin>>n>>m;
  loop(i,n)
  {
    cin>>s[i];
    loop(j,m)
    {
			loop(k,4)	dist[i][j][k]=INT_MAX;
      if(s[i][j]=='V')  sx=i,sy=j;
      else if(s[i][j]=='H') dtx=i,dty=j;
    }
  }
  solve();
	int res=-1;
	loop(i,4)
	{
		if(dist[dtx][dty][i]==INT_MAX)	continue;
		res=dist[dtx][dty][i];
	}
	cout<<res<<"\n";
  return 0;
}
