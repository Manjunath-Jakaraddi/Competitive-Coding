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
int n,m,buksz,cnt;
vi buk;
vi arr;
int main()
{
	prep();
  cin>>n>>m;
  buksz=(n/m);
  arr.assign(n,0);
  buk.assign(m,0);
  loop(i,n) cin>>arr[i];
  loop(i,n) buk[arr[i]%m]++;
  loop(i,m)
  {
    if(buk[i]>buksz)
    {
      cnt+=(buk[i]-buksz);
      buk[(i+1)%m]=(buk[i]-buksz);
    }
  }
  cout<<cnt<<"\n";
	return 0;
}
