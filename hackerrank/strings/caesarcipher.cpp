#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int main()
{
  int n;
  cin>>n;
  string s,tmp="";
  cin>>s;
  int k;
  cin>>k;
  k=k%26;
  for(char c:s)
  {
    if(c<='z'&&c>='a')
    {
      tmp.push_back((((c-'a')+k)%26)+'a');
    }
    else if(c<='Z'&&c>='A')
    {
      tmp.push_back((((c-'A')+k)%26)+'A');
    }
    else
    {
      tmp.push_back(c);
    }
  }
  cout<<tmp<<"\n";
	return 0;
}
