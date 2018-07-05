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
int n,l,r;
vii eprs;
map<int,int> mmap; // person to ids
set<int> st;
vi par,rnk,maxofSet;
void initialise()
{
  par.assign(200005,0);
  rnk.assign(200005,0);
  maxofSet.assign(200005,1);
  loop(i,200004)  par[i]=i;
}
int findParent(int i)
{
  return ((par[i]==i)?i:par[i]=findParent(par[i]));
}
bool isSameSet(int i,int j)
{
  return (findParent(i)==findParent(j));
}
int unionSet(int i,int j)
{
  if(!isSameSet(i,j))
  {
    int x=findParent(i);
    int y=findParent(j);
    if(rnk[x]>rnk[y])
    {
      par[y]=x;
      maxofSet[x]+=maxofSet[y];
      return maxofSet[x];
    }
    else
    {
      par[x]=y;
      if(rnk[x]==rnk[y])  rnk[y]++;
      maxofSet[y]+=maxofSet[x];
      return maxofSet[y];
    }
  }
  else
  {
    int x=findParent(i);
    return maxofSet[x];
  }
}
int main()
{
	prep();
  initialise();
  cin>>n;
  loop(i,n)
  {
    cin>>l;
    eprs.pb({l,0});
    st.insert(l);
  }
  loop(i,n)
  {
    cin>>r;
    eprs[i].second=r;
    st.insert(r);
  }
  int id=1;
  for(auto it:st)  mmap[it]=id++;
  loop(i,n)
  {
    l=eprs[i].first;
    r=eprs[i].second;
    eprs[i].first=mmap[l];
    eprs[i].second=mmap[r];
  }
  int mx=0;
  loop(i,n)
  {
    mx=max(mx,unionSet(eprs[i].first,eprs[i].second));
    cout<<mx<<"\n";
  }
	return 0;
}
