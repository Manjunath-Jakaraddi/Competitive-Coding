#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007

int arr[101];
int main()
{
  int n,k;
  cin>>n>>k;
  for(int i=0;i<n;i++)  cin>>arr[i];
  int cnt=0,pages=1;
  for(int i=0;i<n;i++)
  {
    int tmp=(arr[i]/k)+(arr[i]%k==0?0:1);
    int q=0;
    for(int j=pages;j<pages+tmp;j++)
    {
      if(arr[i]>=k)
      {
        if(j>q&&j<=q+k) cnt++;
        q=q+k;
        arr[i]-=k;
      }
      else
      {
        if(j>q&&j<=q+arr[i])  cnt++;
      }
    }
    pages+=tmp;
  }
  cout<<cnt<<"\n";
  return 0;
}
