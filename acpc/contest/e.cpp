#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class UFDS
{
  vector<int> pr,rnk;
  int n;
  public:
  int ans = 0;
    UFDS(int n)
    {
      this->n=n;
      pr.assign(n,0);
      rnk.assign(n,0);
      for(int i=0;i<n;i++) pr[i]=i;
    }
    int findSet(int i)
    {
      return ((pr[i]==i)?i:(pr[i]=findSet(pr[i])));
    }
    bool isSameSet(int i,int j)
    {
      return (findSet(i)==findSet(j));
    }
    void unionSet(int i,int j)
    {
      if(!isSameSet(i,j))
      {
        int x=findSet(i),y=findSet(j);
        if(rnk[x]>rnk[y]) pr[y]=x;
        else
        {
          pr[x]=y;
          if(rnk[x]==rnk[y])  rnk[y]++;
        }
      }
    }
    int noOfSets()
    {
      set<int> st;
      for(int i=0;i<n;i++) st.insert(findSet(i));
      return ((int)st.size());
    }
};

int nax = 1005;
int main()
{
  UFDS st(nax);
  int n, m;
  cin >> n >> m;
  int x, y;
  vector<pair<int, int> > edges;
  vector<int> neigbours;
  for (int i=0; i<m; i++) {
    cin>>x>>y;
    if (x == 1) {
        neigbours.push_back(y);
    }
    edges.push_back(make_pair(x, y));
  }
  for (int x : neigbours) {
    st.unionSet(1, x);
  }
  st.ans = 0;
  int ans = 0;
  for (pair<int, int> pr : edges) {
    int fs = st.findSet(pr.first), ss = st.findSet(pr.second);
    int hs = st.findSet(1);
    if (fs == hs && ss != hs) {
        ans++;
    }
    st.unionSet(pr.first, pr.second);
  }
  cout << ans << "\n";
  return 0;
}
