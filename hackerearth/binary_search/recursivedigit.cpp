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
string s;
int k;
int super_digit(int l,int r)
{
  if(l>r) return 0;
  if(l==r)  return s[l]-'0';
  int ld=super_digit(l,(l+r)/2);
  int rd=super_digit(((l+r)/2)+1,r);
  int num;
  num=ld+rd;
  if(num==19) return 1;
  else if(num<10) return (ld+rd);
  return ((num/10)+(num%10));
}
int main()
{
	prep();
  cin>>s>>k;
  int res=super_digit(0,(int)s.length()-1);
  s=to_string(res*k);
  cout<<super_digit(0,(int)s.length()-1)<<"\n";
	return 0;
}
