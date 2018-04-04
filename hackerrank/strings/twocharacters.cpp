#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
bool validate(string s)
{
  for(int i=1;i<s.length();i++)
    if(s[i-1]==s[i])  return false;
  return true;
}
int main()
{
  int n,cnt=0;
  cin>>n;
  string s;
  cin>>s;
  set<char> st;
  for(char c:s)  st.insert(c);
  for(auto i=st.begin();i!=st.end();i++)
  {
    for(auto j=i;j!=st.end();j++)
    {
      if(j==i)  continue;
      string tmp="";
      for(char c:s) if(c==*i||c==*j)  tmp.push_back(c);
      if(validate(tmp)) cnt=max(cnt,(int)tmp.length());
    }
  }
  cout<<cnt<<"\n";
	return 0;
}
