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
int n,x,y;
map<int,set<int>> mmap;
int main()
{
	prep();
  cin>>n;
  loop(i,n)
  {
      cin>>x>>y;
      mmap[x].insert(y);
  }
  int x1,x2,y1,y2,mx_side=0,resx=-1,resy=-1;
  for(auto it:mmap)
  {
    x1=it.first;
    for(auto i=it.second.begin();i!=it.second.end();i++)
    {
      y1=*i;
      for(auto j=next(i);j!=it.second.end();j++)
      {
        y2=*j;
        if(y2-y1>mx_side)
        {
          x2=x1+(y2-y1);
          if(mmap[x2].find(y1)!=mmap[x2].end()&&mmap[x2].find(y2)!=mmap[x2].end())
          {
            mx_side=y2-y1;
            resx=x1;resy=y1;
          }
        }
      }
    }
  }
  cout<<resx<<" "<<resy<<"\n";
	return 0;
}
