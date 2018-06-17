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
int main()
{
	prep();
  int a,b,c,d;
  char mat[50][50];
  memset(mat,'.',sizeof mat);
  cin>>a>>b>>c>>d;
  vector<pair<int,char> > arr;
  arr.pb({a,'A'});
  arr.pb({b,'B'});
  arr.pb({c,'C'});
  arr.pb({d,'D'});
  sort(all(arr));
  reverse(all(arr));
  int col=min(50,arr[0].first);
  int st=0;
  while()
  return 0;
}
