#include<bits/stdc++.h>
using namespace std;
class fenwick
{
  private:
    int n;
    int *table;
  public:
    fenwick(int size)
    {
      this->n=size;
      table = new int[size];
    }
    void update(int i,int value)
    {
      while(i<n)
      {
        table[i]+=value;
        i+=(i&-i);
      }
    }
    int sum(int i)
    {
      int sm=0;
      while(i>0)
      {
        sm+=table[i];
        i-=(i&-i);
      }
      return sm;
    }
    int rangeSum(int i,int j)
    {
      return sum(j)-sum(i-1);
    }
};

int main()
{
  int n,t,x;
  cin>>t;
  while(t--)
  {
    cin>>n;
    int inv=0;
    fenwick f(n+1);
    for(int i=0;i<n;i++)
    {
      cin>>x;
      inv+=f.rangeSum(x+1,n);
      f.update(x,1);
    }
    inv&1?cout<<"NO\n":cout<<"YES\n";
  }
  return 0;
}
