#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007

int arr[100005],n,m;
int main()
{
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>arr[i];
  }
  sort(arr,arr+m);
  int mx=0;
  mx=max(mx,arr[0]);
  for(int i=1;i<m;i++)  mx=max(mx,(arr[i]-arr[i-1])/2);
  mx=max(mx,(n-1-arr[m-1]));
  cout<<mx<<"\n";
  return 0;
}
