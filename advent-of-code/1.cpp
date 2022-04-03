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
  vector<ll> arr;
  int n;
  while(cin >> n) {
    arr.pb(n);
  }
  n = arr.size();
  sort(all(arr));
	for(int i=0; i<n-2; i++) {
		int l=i+1, r=n-1;
		while(l<r) {
			if(arr[i]+arr[l]+arr[r] < 2020) l++;
			else if (arr[i]+arr[l]+arr[r] > 2020) r--;
			else {
				cout<<(arr[i]*arr[l]*arr[r])<<"\n";
				return 0;
			}
		}
	}
	cout<<"not found"<<"\n";
	return 0;
}


// map<int,int> mmap;
// for(int ele: arr) {
// 	if(mmap[2020-ele]!=0) {
// 		cout<<((2020-ele)*ele)<<"\n";
// 		break;
// 	}
// 	mmap[ele]=1;
// }
