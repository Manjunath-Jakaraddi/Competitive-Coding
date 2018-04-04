#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define N 200010
#define INF 1000000007
ll tree[N],arr[N];
vector<int> q[N];
ll n;
void add(int idx)
{
  while(idx<n)
  {
    tree[idx]++;
    idx+=(idx&-idx);
  }
}
ll sum(int idx)
{
  ll sm=0;
  while(idx)
  {
    sm+=tree[idx];
    idx-=(idx&-idx);
  }
  return sm;
}
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>arr[i];
    q[min(arr[i],n)].push_back(i);
  }
  ll ans=0;
  for(int i=n;i>=1;i--)
  {
    for(int t:q[i])
      add(t);
    ans+=sum(min(1LL*i-1,arr[i]));
  }
  cout<<((1LL)*ans)<<"\n";
	return 0;
}
