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
int lcs[100][100];
int main()
{
	prep();
  cin>>s1>>s2;
  s1=" "+s1;
  s2=" "+s2;
  for(int i=1;i<s1.length();i++)
  {
    for(int j=1;j<s2.length();j++)
    {
      if(s1[i]==s2[j])  lcs[i][j]=1+lcs[i-1][j-1];
      else  lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
    }
  }
  loop(i,s1.length())
    loop(j,s2.length())
      cout<<lcs[i][j]<<(j==(int)s2.length()-1?"\n":" ");
  cout<<lcs[(int)s1.length()-1][(int)s2.length()-1]<<"\n";
  return 0;
}
