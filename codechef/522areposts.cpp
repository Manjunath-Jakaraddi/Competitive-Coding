#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
map<string,int> mmap;
int main()
{
  int t,n;
	cin>>n;
	string s1,s2,s3;
	mmap["polycarp"]=1;
	int mx=0;
	while(n--)
	{
		cin>>s1>>s2>>s3;
		std::transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
		std::transform(s3.begin(), s3.end(), s3.begin(), ::tolower);
		mmap[s1]=1+mmap[s3];
		mx=max(mmap[s1],mx);
	}
	cout<<mx;

  return 0;
}
