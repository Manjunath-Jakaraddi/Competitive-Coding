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
int main()
{
	prep();
  int t;
  cin>>t;
  while(t--) {
    int n,x;
    set<int> st;
    vi arr;
    cin>>n;
		int pairInd = -1;
    loop(i,n) {
      cin>>x;
      arr.pb(x);
			if(i>0 && arr[i-1] == arr[i])	pairInd = i;
      st.insert(x);
    }
		if(st.size() == 1) {
			cout<<"1\n";
			loop(i, n) cout<<"1 ";
			cout<<"\n";
		} else {
			vi res(n);
			loop(i, n) res[i] = (i&1)+1;
			if(n&1 && pairInd != -1) {
				for(int i=pairInd; i<n; i++) {
					res[i] = res[i] == 1 ? 2 : 1;
				}
			} else if(n&1 && arr[0]!=arr[n-1]) {
				res[n-1] = 3;
			}
			cout<<(res[n-1] == 3 ? 3 : 2)<<"\n";
			loop(i, n) cout<<res[i]<<" "; cout<<"\n";
		}
  }
	return 0;
}
