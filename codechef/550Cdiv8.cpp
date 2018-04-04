#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int getnum(string s)
{
	int n=s.length();
	int num;
	if(n>=3)
		num+=((s[n-3]-'0')*100);
	if(n>=2)
		num+=((s[n-2]-'0')*10);
	if(n>=1)
		num+=num=(s[n-1]-'0');
	return num;
}
/*
bool div4(string s)
{
	int n=s.length();
	int num=(s[n-1]-'0')+(s[n-2]-'0')
}*/
int main()
{
  string s;
	cin>>s;
	/*while(!div8(s)&&s.length())
	{
		int len=s.length()-1;
		if(len>-1&&(s[len]-'0')%2!=0)
		{
			s.erase(len,1);
		}
		else if(len-1>-1&&(s[len-1]-'0')%2!=0)
		{
			s.erase(len-1,1);
		}
		else if(len-2>-1)
		{
			s.erase(len-2,1);
		}
	}*/
	while(s.length())
	{
		int len=s.length()-1;
		if(getnum(s)%8==0)
			break;
		if((s[len]-'0')%2!=0)
		{
			s.erase(len,1);
		}
		else if(len>1&&((s[len-1]-'0')*10+(s[len]-'0')%4)!=0)
		{
			s.erase(len-1,1);
		}
		else if(len>2)
		{
			s.erase(len-2,1);
		}
	}
	if(!s.length())
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl<<s<<endl;
	}
  return 0;
}
