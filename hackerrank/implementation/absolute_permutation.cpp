#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int arr[100005];
int main()
{
  int n,k,t;
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    if(k&&n%(2*k)!=0)  cout<<"-1\n";
    else
    {
      if(!k)  for(int i=1;i<=n;i++) cout<<i<<" ";
      else
      {
        for(int i=1;i<=n;i++)
        {
          cout<<i+k<<" ";
          if(i%k==0)  k=-k;
        }
      }
      cout<<"\n";
    }
  }
  return 0;
}
