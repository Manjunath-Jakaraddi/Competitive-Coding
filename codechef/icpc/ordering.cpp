#include<bits/stdc++.h>
using namespace std;
int a[3][3];
int sm[3];
int n;
string solve()
{
	int p[3];
	int k=0;
	map<int,int> mmap;
	for(int i=0;i<3;i++)	mmap[sm[i]]=i;
	sort(mmap.begin(),mmap.end());
	map<int,int>::iterator iter;
	for(iter=mmap.begin(),k=0;iter!=mmap.end();iter++)	p[k++]=mmap->second;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)	sm[j]-=a[i][j];
		if(sm[p[0]]>sm[p[1]]&&sm[p[0]]>sm[p[2]]&&sm[p[1]]>sm[p[2]])	continue;
		else	return "no";
	}
	return "yes";
}
int main()
{
	cin>>n;
	int sum;
	while(n--)
	{
		for(int i=0;i<3;i++)
		{
			sum=0;
			for(int j=0;j<3;j++)
			{
				cin>>a[i][j];
				sm+=a[i][j];
			}
			sm[i]=sum;
		}
		cout<<solve()<<endl;
	}
	return 0;
}
