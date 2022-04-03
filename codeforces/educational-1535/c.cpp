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
    string s;
    cin>>s;
    int n=s.length();
    int res = n;
    int l=0, r=1;
    while(s[l] == '?') l++;
    int pat = (s[l] - '0')&1;
    if(l&1) pat=(1-pat);
    l=0;
    cout<<"pat "<<pat<<"\n";
    while(l<n-1 && r<n) {
      if(s[r] != '?' && s[r-1]==s[r]) {
        cout<<l<<" "<<r<<" 1\n";

        res+=(r-l+1)*(r-l)/2;
        l = r;
        r = l+1;
        pat = (1-pat);

      }
      else {
        if(pat) {
          if(((s[r] - '0')&1)) {
            cout<<l<<" "<<r<<" 2\n";

            res+=(r-l+1)*(r-l)/2;
            l=r;
            r=l+1;
          } else {
            r++;
          }
        }
        else {
          if(!((s[r] - '0')&1)) {
            cout<<l<<" "<<r<<" 2\n";
            res+=(r-l+1)*(r-l)/2;
            l=r;
            r=l+1;
          } else {
            r++;
          }
        }
      }
    }
    cout<<res<<"\n";
  }
	return 0;
}
