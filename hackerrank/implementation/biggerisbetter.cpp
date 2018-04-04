//USING NEXT PERMUTATION
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    if(next_permutation(s.begin(),s.end()))
      cout<<s<<"\n";
    else
      cout<<"no answer\n";
  }
  return 0;
}
// USING SORTING
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    string s;
    cin>>s;
    int i;
    for(i=0;i<s.length()-1;i++)
    {
      if(s[i]<s[i+1])
      {
        sort(s+i,s+n);
        break;
      }
    }
    i==n?cout<<"no answer":cout<<s<<"\n";
  }
  return 0;
}
