#include<bits/stdc++.h>
using namespace std;
//int a[105],b[105];
int main()
{
	int n,k;
//	int x;
//	int cnt=0;
//	cin>>n;
//	for(int i=0;i<n;i++)
//	{
//		cin>>x;
//		dpa[x]++;	
//	}
//	cin>>k;
//	for(int i=0;i<k;i++)
//	{
//		cin>>x;
//		dpb[x]++;
//	}
//	for(int i=1;i<=101;i++)
//	{
//		if(dpa[i]&&dpb[i])
//		{
//			x=min(dpa[i],dpb[i]);
//			dpa[i]-=x;
//			dpb[i]-=x;
//			cnt+=x;
//		}
//		if(dpa[i]&&dpb[i-1])
//		{
//			x=min(dpa[i],dpb[i-1]);
//			dpa[i]-=x;
//			dpb[i-1]-=x;
//			cnt+=x;
//		}
//		if(dpa[i-1]&&dpb[i])
//		{
//			x=min(dpa[i-1],dpb[i]);
//			dpa[i-1]-=x;
//			dpb[i]-=x;
//			cnt+=x;
//		}
//	}
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)	cin>>a[i];
	cin>>k;
	vector<int> b(k);
	for(int j=0;j<k;j++)	cin>>b[j];
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int i=0,j=0;
	int cnt=0;
	while(i<n||j<k)
	{
		if(abs(a[i]-b[j])<=1)
		{
			cnt++,i++,j++;
		}
		else if(a[i]<b[j])
			i++;
		else
			j++;
	}
	cout<<cnt;
	return 0;
}
