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
string s1,s2;
int main()
{
	prep();
  cin>>s1>>s2;
  int n=s1.length(),m=s2.length();
  int i=n-1,j=m-1;
  while(i>=0&&j>=0) if(s1[i]==s2[j])  i--,j--;
                    else  break;
  cout<<i+j+2<<"\n";
	return 0;
}
