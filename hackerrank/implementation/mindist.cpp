#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >arr;
bool comp(pair<int,int> &a,pair<int,int> &b)
{
  return a.first < b.first ;
}
int main()
{
  int n,x;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    arr.push_back({x,i});
  }
  sort(arr.begin(),arr.end(),comp);
  int mn=INT_MAX;
  for(int i=0;i<n-1;i++)
  {
    if(arr[i].first-arr[i+1].first==0)  mn=min(mn,abs(arr[i].second-arr[i+1].second));
  }
  mn==INT_MAX?cout<<"-1\n":cout<<mn<<"\n";
  return 0;
}
