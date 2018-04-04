#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int main()
{
  int n,k;
  string s;
  cin>>n>>k>>s;
  int l=0,r=0;
  int ans=0,cnt=0;
	while(l!=s.length()-1&&r!=s.length()-1)
  	{
		int b=k+1;
		while(l<s.length()&&r<s.length())
		{
			s[r]=='b'?b--:0;
			if(b==0)	break;
			r++;
		}
		ans=max(ans,r-l);
		b=k;
		while(l<s.length()&&r<s.length())
		{
			s[l]=='b'?b--:0;l++;
			if(b==0)	break;
		}
	}
	cout<<ans;
  return 0;
}
