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
// 1 Indexed Use only
int main()
{
  fenwick f1(5);
  for(int i=1;i<6;i++)  f1.update(i,i);
  cout<<f1.rangeSum(2,4)<<"\n";
  f1.update(3,5);
  cout<<f1.rangeSum(2,4)<<"\n";
  return 0;
}
