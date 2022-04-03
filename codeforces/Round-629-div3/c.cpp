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
		int n;
		string str;
		cin>>n>>str;
		string res1, res2;
		loop(i, n)	{
			res1.pb('0');
			res2.pb('0');
		}
		if(str[0] == '1') {
			res1[0] = '2';
			res2[0] = '2';
		} else if(str[0] == '2') {
			res1[0] = '1';
			res2[0] = '1';
		}
		bool sw = true;
		for(int i=1; i<n; i++) {
			if(str[i] == '1') {
				if(sw) res1[i] = '1';
				else res2[i] = '1';
				sw = false;
			} else if(str[i] == '2') {
				if(sw)	{
					res1[i] = '1';
					res2[i] = '1';
				} else {
					res1[i] = '0';
					res2[i] = '2';
				}
			}
		}
		cout<<res1<<"\n"<<res2<<"\n";
	}
	return 0;
}
