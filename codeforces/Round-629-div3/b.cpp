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
		int n, k;
		cin>>n>>k;
		int round = 1;
		int sm=1;
		while(k - sm >0) {
			round++;
			sm+=round;
		}
		sm-=round;
		round--;
		int dist = k-sm-1;
		string res="";
		loop(i, n)	res.pb('a');
		res[n-2-round] = 'b';
		res[n-1- dist] = 'b';
		cout<<res<<"\n";
	}
	return 0;
}
