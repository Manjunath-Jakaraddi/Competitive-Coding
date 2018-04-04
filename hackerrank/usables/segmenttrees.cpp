#include<bits/stdc++.h>
using namespace std;
class segmentTree
{
  private:
    int n;
    int *lo,*hi,*mn,*delta;
  public:
    segmentTree(int n)
    {
      this->n=n;
      lo = new int[4*n+1];
      hi = new int[4*n+1];
      mn = new int[4*n+1];
      delta = new int[4*n+1];
      init(1,0,n-1);
    }
    void increment(int a,int b,int val)
    {
      recurincr(1,a,b,val);
    }
    int minimum(int a,int b)
    {
      return recurmin(1,a,b);
    }
    void init(int i,int a,int b)
    {
      lo[i]=a;
      hi[i]=b;
      if(a==b)  return;
      int m=(a+b)/2;
      init(2*i,a,m);
      init(2*i+1,m+1,b);
    }
  private:
    void prop(int i)
    {
      delta[2*i]+=delta[i];
      delta[2*i+1]+=delta[i];
      delta[i]=0;
    }
    void update(int i)
    {
      mn[i]=min(mn[2*i]+delta[2*i],mn[2*i+1]+delta[2*i+1]);
    }
    void recurincr(int i,int a,int b,int val)
    {
      if(b<lo[i]||a>hi[i])  return;
      if(a<=lo[i]&&hi[i]<=b)
      {
        delta[i]+=val;
        return;
      }
      prop(i);
      recurincr(2*i,a,b,val);
      recurincr(2*i+1,a,b,val);
      update(i);
    }
    int recurmin(int i,int a,int b)
    {
      if(a>hi[i]||b<lo[i])  return INT_MAX;
      if(a<=lo[i]&&hi[i]<=b)
      {
        return mn[i]+delta[i];
      }
      prop(i);
      int minLeft=recurmin(2*i,a,b);
      int minRight=recurmin(2*i+1,a,b);
      update(i);
      return min(minLeft,minRight);
    }
};
int main()
{
  int n,x;
  cin>>n;
  segmentTree st(n);
  for(int i=0;i<n;i++)
  {
    cin>>x;
    st.increment(i,i,x);
  }
  // 1 2 3 2 1 4
  cout<<st.minimum(0,n-1)<<"\n";
  cout<<st.minimum(2,4)<<"\n";
  st.increment(2,4,-3);
  //1 2 0 -1 -2 4
  cout<<st.minimum(2,4)<<"\n";
  cout<<st.minimum(0,n-1)<<"\n";
  return 0;
}
