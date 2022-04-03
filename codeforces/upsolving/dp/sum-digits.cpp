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
    int m, n;
    cin>>m>>n;
		if(m==1 && n<10) {
			cout<<n<<" "<<n<<endl;
			return 0;
		}
    if(!n || (9*m) < n) {
			cout<<"-1 -1\n";
			return 0;
		}
		string max_res = "";
		int rem_n = n;
		for(int i=0; i<m; i++) {
			if(rem_n >= 9) {
				max_res.pb('9');
				rem_n-=9;
			} else {
				max_res.pb('0' + rem_n);
				rem_n=0;
			}
		}
		string min_res = "";
		rem_n = n-1;
		for(int i=0; i<m; i++) {
			if(rem_n >=9) {
				min_res.pb('9');
				rem_n-=9;
			} else {
				min_res.pb('0' + rem_n);
				rem_n=0;
			}
		}
		reverse(all(min_res));
		min_res[0] +=1;
		cout<<min_res<<" "<<max_res<<"\n";
    return 0;
}
