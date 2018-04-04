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
    void rangeUpdate(int i,int j,int value)
    {
      update(i,value);
      update(j+1,-value);
    }
};

int main()
{
  fenwick f(7);
  //0 0 0 0 0 0
  f.rangeUpdate(2,4,3);
  //0 3 3 3 3 0
  f.rangeUpdate(1,3,2);
  //2 5 5 3 0 0
  for(int i=1;i<7;i++)
  {
    cout<<f.sum(i)<<"\n";
  }
  return 0;
}
