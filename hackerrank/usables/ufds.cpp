#include<bits/stdc++.h>
using namespace std;
class UFDS
{
  vector<int> pr,rnk;
  int n;
  public:
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
int main()
{
  UFDS st(5);
  cout<<st.noOfSets()<<"\n";
  st.unionSet(1,3);
  cout<<st.noOfSets()<<"\n";
  st.unionSet(2,4);
  cout<<st.noOfSets()<<"\n";
  st.unionSet(2,3);
  cout<<st.noOfSets()<<"\n";
  return 0;
}
