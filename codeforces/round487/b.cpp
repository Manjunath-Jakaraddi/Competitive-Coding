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
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int get(char c)
{
  if(c=='0'||c=='1')  return c-'0';
  return 2;
}
int buc[2002][3];
int main()
{
	prep();
  int n,p;
  string s;
  cin>>n>>p>>s;
  for(int i=0;i<s.length();i++)
    buc[i%p][get(s[i])]++;
  bool poss=false;
  for(int i=0;i<p;i++)
  {
    if(buc[i][0]&&buc[i][1])
    {
      poss=true;
      break;
    }
    else if(buc[i][0]&&buc[i][2])
    {
      int j=i;
      poss=true;
      while(j<s.length())
      {
        if(s[j]=='.')
        {
          s[j]='1';
          break;
        }
        j+=p;
      }
      break;
    }
    else if(buc[i][1]&&buc[i][2])
    {
      poss=true;
      int j=i;
      while(j<s.length())
      {
        if(s[j]=='.')
        {
          s[j]='0';
          break;
        }
        j+=p;
      }
      break;
    }
    else if(!buc[i][0]&&!buc[i][1]&&buc[i][2]>1)
    {
      poss=true;
      int j=i;
      while(j<s.length())
      {
        if(s[j]=='.')
        {
          s[j]='0';
          break;
        }
        j+=p;
      }
      while(j<s.length())
      {
        if(s[j]=='.')
        {
          s[j]='1';
          break;
        }
        j+=p;
      }
      break;
    }
  }
  if(!poss)  cout<<"No\n";
  else
  {
    for(auto ch:s)
    {
      if(ch=='.') cout<<"0";
      else  cout<<ch;
    }
    cout<<"\n";
  }
  return 0;
}
