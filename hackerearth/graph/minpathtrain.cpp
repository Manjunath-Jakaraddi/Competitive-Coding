#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define oo 987654321
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
map<string,int> mmap;
int N,E,wt,q,x,y;
string s1,s2;
int edges[101][101];
void solve()
{
  loop(k,N) loop(i,N) loop(j,N) edges[i][j]=min(edges[i][j],edges[i][k]+edges[k][j]);
}
int main()
{
	prep();
  cin>>N>>E;
  loop(i,N) loop(j,N) edges[i][j]=oo;
  loop(i,N)
  {
    cin>>s1;
    mmap[s1]=i;
  }
  loop(i,E)
  {
    cin>>s1>>s2>>wt;
    x=mmap[s1],y=mmap[s2];
    edges[x][y]=edges[y][x]=wt;
  }
  solve();
  cin>>q;
  while(q--)
  {
    cin>>s1>>s2;
    x=mmap[s1],y=mmap[s2];
    cout<<((edges[x][y]==oo)?-1:edges[x][y])<<"\n";
  }
  return 0;
}
