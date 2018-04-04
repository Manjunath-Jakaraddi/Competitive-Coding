#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int nob(ull x)
{
	int cnt=0;
	while(x)
	{
		x>>=1;
		cnt++;
	}
	return cnt;
}
ull maxd[100005];
int main()
{
	int n;
	cin>>n;
	vector<ull> v(n),a[65];
	for(int i=0;i<n;i++)
	{
		cin>>v[i];
		a[nob(v[i])].push_back(v[i]);
	}
	int mind=0;
	for(int i=64;i>0;i--)
	{
		if(a[i].size())
		{
			maxd[mind++]=a[i][0];
			for(int j=1;j<a[i].size();j++)
			{
				ull tmp=a[i][0]^a[i][j];
				a[nob(tmp)].push_back(tmp);
			}
		}
	}
	ull res=0;
	for(int i=0;i<mind;i++)
	{
		if((res^maxd[i])>res)	res^=maxd[i];
	}
	cout<<res;
	return 0;
}
