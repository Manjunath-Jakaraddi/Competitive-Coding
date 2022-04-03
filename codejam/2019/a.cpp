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
  int n;
  cin>>n;
  loop(j, n) {
    string str, res;
    cin>>str;
    loop(i, str.length()) {
      if(str[i] == '4') {
        str[i]='3';
        res.push_back('1');
      } else res.push_back('0');
    }
    string res1;
    int i=0;
    while(res[i]=='0')  i++;
    while(i<res.length()) res1.push_back(res[i++]);
    cout<<"Case #"<<j+1<<": "<<str<<" "<<res1<<"\n";
  }
	return 0;
}
