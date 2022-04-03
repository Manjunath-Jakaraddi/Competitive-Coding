#include<bits/stdc++.h>
using namespace std;
map<string,string> mmap;
int main()
{
	int n,m;
	cin>>n>>m;
	string s1,s2;
	vector<string> v;
	while(n--)
	{
		cin>>s1>>s2;
		mmap[s2+";"]=s1;
	}
	while(m--)
	{
		cin>>s1>>s2;
		v.push_back(s1+" "+s2+" #"+mmap[s2]);
	}
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	return 0;
}
