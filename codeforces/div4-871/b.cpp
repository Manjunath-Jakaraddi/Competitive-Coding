#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>

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
    int tt;
    cin>>tt;
    while(tt--) {
        int x, n;
        cin>>n;
        int ans=0, mx=INT_MIN;
        loop(i, n)  {
            cin>>x;
            ans += (x == 0);
            mx = max(mx, ans);
            if (x)  ans=0;
        }
        cout<<mx<<"\n";
    }
    return 0;
}
