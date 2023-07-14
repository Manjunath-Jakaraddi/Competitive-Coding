#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
#include<assert.h>

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
#define oo 1e5+5
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int gcd(int a, int b) {
   return b ? gcd(b, a % b) : a;
}

int main()
{
    prep();
    vector<vector<ll> > a(1500, vector<ll>(1500, 0));
    vector<ll> dp(1e6+6);
    // ll ind=1;
    // for (int r=0; ind<=1e6; r++) {
    //     int i=r, j=1;
    //     while(i > 0) {
    //         sum[i][j] = (ind*ind) + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    //         dp[ind] = sum[i][j];
    //         i--;
    //         j++;
    //         ind++;
    //     }
    // }
    ll cur=1;
    for (int l=2; l<1500&&cur<=1e6; l++) {
        for (int i=l-1; i>=1; i--) {
            a[i][l-i] = (cur*cur) + a[i-1][l-i] + a[i][l-1-i] - a[i-1][l-1-i];
            dp[cur] = a[i][l-i];
            cur++;
        }
    }
    int tt;
    cin>>tt;
    while(tt--) {
        int n;
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    return 0;
}