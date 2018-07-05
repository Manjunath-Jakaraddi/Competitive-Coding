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
int findOptimal(int N)
{
  if(N<=6)  return N;
  int screen[N+1]={0};
  int b,n;
  for(int i=1;i<=6;i++) screen[i]=i;
  for(n=7;n<=N;n++)
    // for(b=n-3;b>=1;b--)
    //   screen[n]=max(screen[n],(n-b-1)*screen[b]);
    for(b=0;b<3;b++)
      screen[n]=max(screen[n],(b+2)*screen[n-3-b]);
  rep(i,1,N)  cout<<screen[i]<<" "; cout<<"\n";
  return screen[N];
}
int main()
{
	prep();
  int N;
  cin>>N;
  cout<<findOptimal(N)<<"\n";
  return 0;
}
