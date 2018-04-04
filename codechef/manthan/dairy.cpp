#include<bits/stdc++.h>
using namespace std;
map<string,int> mmap;
int main()
{
	int n;
	cin>>n;
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		if(mmap[s]==0)
		{
			cout<<"NO"<<endl;
			mmap[s]=1;
		}
		else
		{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}
