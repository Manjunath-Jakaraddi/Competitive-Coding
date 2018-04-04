#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int main()
{
  int n,a;
  cin>>n;
  ll arr[6]={0};
  for(int t=1;t<5;t++)
  {
    for(int i=1;i<=n*n;i++)
    {
      scanf("%1d",&a);
      if(a==(i&1))  arr[t]++;
    }
  }
  sort(arr+1,arr+5);
  cout<<arr[1]<<" "<<arr[2]<<" "<<arr[3]<<" "<<arr[4]<<"\n";
  ll res=arr[1]+arr[2]+(2*n*n)-arr[3]-arr[4];
  cout<<(1LL)*res<<"\n";
	return 0;
}
