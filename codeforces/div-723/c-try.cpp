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
int n;
ll arr[200005];
priority_queue<ll> q;
int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i];
  int i=0;
  int res=0;
  ll sum = 0;
  while(i<n) {
    sum+=arr[i];
    res++;
    q.push(-arr[i]);
    i++;
    while(sum<0) {
      sum+=q.top();q.pop();
      res--;
    }
  }
  cout<<res<<"\n";
	return 0;
}
