#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define pb push_back
#define pf printf
#define sf scanf
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(auto i=s; i<=e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int n;
int arr[100],lis[100];
int main()
{
	prep();
  cin>>n;
  rep(i,1,n)
  {
    cin>>arr[i];
    lis[i]=1;
  }
  for(int i=2;i<=n;i++)
  {
    for(int j=1;j<i;j++)
    {
      if(arr[i]>arr[j]) lis[i]=max(lis[i],1+lis[j]);
    }
  }
	cout<<*max_element(arr,arr+n)<<"\n";
  return 0;
}
