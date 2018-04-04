#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
uint64_t ToInteger(string& s)
{
	istringstream istr(s);
	uint64_t v;
	istr >> v;
	return v;
}

string ToString(uint64_t& v)
{
	ostringstream ostr;
	ostr << v;
	return ostr.str();
}
void solve(string s)
{
  int i=1,n=s.length();
  while(i<=n/2)
  {
    string x=s.substr(0,i);
    uint64_t num=ToInteger(x);
    string tmp="";
    while(tmp.length()<n)
    {
      tmp+=ToString(num);
      num++;
    }
    if(tmp==s)
    {
      cout<<"YES "<<s.substr(0,i)<<"\n";
      return;
    }
    i++;
  }
  cout<<"NO\n";
}
int main()
{
  int t;
  cin>>t;
  string s;
  while(t--)
  {
    cin>>s;
    solve(s);
  }
	return 0;
}
