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
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int t,n;
int arr[100005],BIT[10000007];
void add(int i,int val)
{
  while(i<=10000006)
  {
    BIT[i]+=val;
    i+=(i&-i);
  }
}
ll query(int i)
{
  ll sm=0;
  while(i)
  {
    sm+=BIT[i];
    i-=(i&-i);
  }
  return sm;
}
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    fill(BIT,BIT+10000006,0);
    cin>>n;
    ll inv=0;
    loop(i,n) cin>>arr[i];
    for(int i=0;i<n;i++)
    {
      ll z=query(10000006)-query(arr[i]);
      add(arr[i],1);
      inv+=(z);
    }
    cout<<inv<<"\n";
  }
	return 0;
}
