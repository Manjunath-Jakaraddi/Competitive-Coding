#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s,tmp="";
    cin>>s;
    int cnt=-1,k=0;
    tmp.push_back(s[0]);
    for(int i=0;i<s.length();i++)
    {
      if(s[i]==tmp[k])  cnt++;
      else
      {
        tmp.push_back(s[i]);
        k++;
      }
    }
    cout<<cnt<<"\n";
  }
	return 0;
}
