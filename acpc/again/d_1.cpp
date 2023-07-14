#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>

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
#define rrep(i, s, e) for(auto i=s; i>=e; i--)
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

void solve(unordered_map<ll, vi> &mp) {
    loop(p1,31) {
        int n1=(1<<p1);
        loop(p2,30) {
            int n2=(1<<p2);
            loop(p3,29) {
                int n3=(1<<p3);
                loop(p4, 28) {
                    int n4=(1<<p4);
                    mp[n1+n2+n3+n4]={n1, n2, n3, n4};
                }
            }
        }
    }
}

void querysolve() {
    unordered_map<ll, vi> mp;
    solve(mp);
    int tt, n;
    cin>>tt;
    while(tt--) {
        cin>>n;
        if (!mp.count(n)) cout<<"-1\n";
        else {
            for (int s:mp[n]) cout<<s<<" "; cout<<"\n";
        }
    }
}
int main()
{
    prep();
    querysolve();
    // solve();
    return 0;
}
