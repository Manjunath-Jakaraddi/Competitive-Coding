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
string s1 = "aabcc", s2 = "dbbca" , s3 = "aadbbcbcac";
int n,m;
int dp[202][202];
int main()
{
	prep();
    n = s1.length(); m = s2.length();
	for(int i=1; i<=n; i++) dp[0][i] = (s1[i-1] == s3[i-1]);
	for(int i=1; i<=m; i++) dp[i][0] = (s2[i-1] == s3[i-1]);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(dp[i-1][j]) {
                dp[i][j] = (s2[i-1] == s3[i+j-1]);
            }
            if(dp[i][j-1]) {
                dp[i][j] = (s1[j-1] == s3[i+j-1]);
            }
        }
    }
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=m; j++) {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
