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
int n,k,x,y,wt;
vector<pair<int,ii> > eprs;
vi red;
vi par,rnk,setRed;
int findParent(int i)
{
  return ((par[i]==i)?i:(par[i]=findParent(par[i])));
}
bool isSameSet(int i,int j)
{
  return findParent(i)==findParent(j);
}
void unionSet(int i,int j)
{
  if(!isSameSet(i,j))
  {
    int x=findParent(i);
    int y=findParent(j);
    if(rnk[x]>rnk[y]) par[y]=x;
    else
    {
      par[x]=y;
      if(rnk[x]==rnk[y])  rnk[y]++;
    }
  }
}
bool isSetRed(int x)
{
  int parx=findParent(x);
  return setRed[parx];
}
void paintSetRed(int x)
{
  int parx=findParent(x);
  setRed[parx]=1;
}
void initialise()
{
  par.assign(100005,0);
  rnk.assign(100005,0);
  setRed.assign(100005,0);
  loop(i,100004)  par[i]=i;
}
bool comp(pair<int,ii> a,pair<int,ii> b)
{
  return (a.first>b.first);
}
int main()
{
	prep();
  initialise();
  ll res=0;
  cin>>n>>k;
  red.assign(n+1,0);
  loop(i,n-1)
  {
    cin>>x>>y>>wt;
    eprs.pb({wt,{x+1,y+1}});
    res+=wt;
  }
  loop(i,k)
  {
    cin>>x;
    red[x+1]=1;
  }
  sort(all(eprs),comp);
  loop(i,n-1)
  {
    x=eprs[i].second.first;
    y=eprs[i].second.second;
    wt=eprs[i].first;
    if(!red[x]&&!red[y])
    {
      unionSet(x,y);
      res-=wt;
    }
    else if(red[x]&&!red[y])
    {
      if(!isSetRed(y))
      {
        unionSet(x,y);
        res-=wt;
        paintSetRed(y);
      }
    }
    else if(!red[x]&&red[y])
    {
      if(!isSetRed(x))
      {
        unionSet(x,y);
        res-=wt;
        paintSetRed(x);
      }
    }
  }
  cout<<res<<"\n";
	return 0;
}
