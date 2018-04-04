#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,a[26]={0};
    string s;
    cin>>n>>s;
    int empty=0;
    bool need=false;
    for(int i=0;i<s.length();i++)
    {
      if(s[i]=='_')  empty++;
      else
      {
          if(i>0&&a[s[i]-'A']>0&&s[i]!=s[i-1]) need=true;
          //If not adjacent of same type then there is need to move the bugs
          a[s[i]-'A']++;
          //Just to maintain the counter of the bugs to later check if only single bug exists
          //which leads to unhappy
      }
    }
    bool ok=true;
    int i;
    for(i=0;i<26;i++)   if(a[i]==1) ok=false;
    if(ok&&need&&empty==0) ok=false;
    ok?cout<<"YES\n":cout<<"NO\n";
  }
  return 0;
}
