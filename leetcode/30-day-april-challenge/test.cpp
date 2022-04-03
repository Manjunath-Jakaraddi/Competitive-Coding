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
#define UNIQUE(c) (c).resize(unique(all(c)) - (c).begin())
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
bool isOddfunc(int n) {
	vi cnt;
	int num = n, len=0;
	while(num) {
		num/=10;
		len++;
	}
	// cout<<len<<"\n";
	int sm=0;
	loop(i,n) {
		sm+=i;
		cnt.pb(sm+1);
	}
	// loop(i,len) cout<<cnt[i]<<" "; cout<<"\n";
	vector<bool> isOdd(len);
	loop(i,len) {
		int cur = n / pow(10, (len-i-1));
		// cout<<":"<<cur<<" ";
		if(cnt[i]&1 && cur&1) isOdd[i] = true;
		else if(!(cnt[i]&1) || !(cur&1)) isOdd[i] = false;
	}
	// loop(i,len) cout<<isOdd[i]<<" "; cout<<"\n";
	bool res = isOdd[0];
	rep(i, 1, len-1) {
		if(res && isOdd[i]) {
			res = !res;
		} else if (!res && isOdd[i]) {
			res = !res;
		}
	}
	return res;
}
int main()
{
	prep();
	int q,mx=0;
	cin>>q;
	vi queries(q);
	loop(i,q) {
		cin>>queries[i];
		mx=max(mx, queries[i]);
	}
	vi res;
	string str;
	for(int i=1; ; i++) {
		str = to_string(i);
		if(str[0] == '2' || str[0] == '4' || str[0] == '6' || str[0] == '8') continue;
		res.pb(i);
		if(res.size() > mx) break;
	}
	for(auto it:queries) {
		cout<<"1 "<<res[it-1]<<"\n";
	}
	return 0;
}
