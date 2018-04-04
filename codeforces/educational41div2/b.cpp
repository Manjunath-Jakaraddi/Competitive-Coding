#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int main()
{
  int n,k;
  cin>>n>>k;
  vector<ll> a(n),b(n);
  for(int i=0;i<n;i++)  cin>>a[i];
  for(int i=0;i<n;i++)  cin>>b[i];
  ll sum=0,ans=0,mx=0;
  for(int i=0;i<n;i++)
  {

    if(!b[i]) sum+=a[i];
    if(i>=k&&!b[i-k]) sum-=a[i-k];
    if(b[i])     ans+=a[i];
    mx=max(mx,sum);
  }
  cout<<ans+mx<<"\n";
	return 0;
}
