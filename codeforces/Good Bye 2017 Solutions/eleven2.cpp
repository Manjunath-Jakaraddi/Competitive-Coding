#include<bits/stdc++.h>
using namespace std;
bool f[5005][5005];
bool g[5005][5005];
int main()
{
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.length();i++)
	{
		int cur=0;
		for(int j=i;j<s.length();j++)
		{
			if(s[j]==')')	cur--;
			else		cur++;
			if(cur>=0)	f[i][j]=true;
			else		break;
		}
	}
	for(int i=0;i<s.length();i++)
	{
		int cur=0;
		for(int j=i;j>=0;j--)
		{
			if(s[j]=='(')	cur--;
			else		cur++;
			if(cur>=0)	g[j][i]=true;
			else		break;
		}
	}
	for(int i=0;i<s.length();i++)
	{
		for(int j=i+1;j<s.length();j+=2)
			if(f[i][j]&&g[i][j])	ans++;
	}
	cout<<ans<<endl;
	return 0;
}
