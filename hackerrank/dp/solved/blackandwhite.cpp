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
int n;
map<pair<int,int>,int> mmap;
int main()
{
	prep();
  cin>>n;
  int x,y;
  loop(i,n)
  {
    cin>>x>>y;
    mmap[{x,y}]=1;
  }
  auto it=mmap.begin();
  int basex=it->first.first,basey=it->first.second;
  it++;
  while(it!=mmap.end())
  {
    if(it->first.first==basex)
    {   int secondy=it->first.second;
        if(mmap[{basex+secondy-basey,basey}]&&mmap[{basex+secondy-basey,secondy}])
        {
          cout<<basex<<" "<<basey<<"\n";
          return 0;
        }
    }
    else
    {
      basex=it->first.first;
      basey=it->first.second;
    }
    it++;
  }
	return 0;
}
