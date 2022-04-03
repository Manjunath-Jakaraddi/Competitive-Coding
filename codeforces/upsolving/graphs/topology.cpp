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
int n,m;
int x,y;
int main()
{
	prep();
  cin>>n>>m;
	int deg[n];
	memset(deg, 0, sizeof(deg));
  loop(i,m) {
    cin>>x>>y;
    x--;y--;
		deg[x]++;
		deg[y]++;
  }
  if(m!=n-1 && m!=n) {
    cout<<"unknown topology\n";
    return 0;
  }
  int mxdeg = INT_MIN;
	int twoCnt=0, oneCnt=0;
	loop(i,n) {
		mxdeg = max(mxdeg, deg[i]);
		if(deg[i]==2)	twoCnt++;
		if(deg[i]==1)	oneCnt++;
	}
  if(m==n-1&&mxdeg == n-1) {
    cout<<"star topology\n";
    return 0;
  }
	if(m==n-1 && oneCnt == 2 && twoCnt == n-2) {
		cout<<"bus topology\n";
		return 0;
	}
	if(m==n && twoCnt == n) {
		cout<<"ring topology\n";
		return 0;
	}
  cout<<"unknown topology\n";
	return 0;
}
