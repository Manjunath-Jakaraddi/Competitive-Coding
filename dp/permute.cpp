#include<bits/stdc++.h>
using namespace std;
string s;
void permute(int l,int r)
{
	if(l==r)	cout<<s<<endl;
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			permute(l+1,r);
			swap(s[l],s[i]);
		}
	}
}
int main()
{
	cin>>s;
	permute(0,s.length()-1);
	return 0;
}
