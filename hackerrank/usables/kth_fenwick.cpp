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
    int returnkthtallest(int k)
    {
      int l=1,h=n;
      while(l<h)
      {
        int mid=(l+h)/2;
        if(k<=sum(mid))  h=mid;
        else  l=mid+1;
      }
      return l;
    }
};

int main()
{
  int n,k;
  fenwick f(7);
  int arr[7]={0,8,2,10,100,1,2};
  n=6;
  for(int i=1;i<=n;i++)  f.update(i,arr[i]);
  cin>>k;
  cout<<f.returnkthtallest(k)<<"\n";
  return 0;
}
