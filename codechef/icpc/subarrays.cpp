#include<bits/stdc++.h>
using namespace std;
long long sum[55],prod[55];
int main()
{
	int k,n;
	long long sm=0,pd=1,x,cnt;
	cin>>k;
	while(k--)
	{
		cnt=0;sm=0;pd=1;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			sm+=x;
			pd*=x;
			sum[i]=sm;
			prod[i]=pd;
		}
		prod[0]=1;
		cout<<"Sum : ";
		for(int i=0;i<=n;i++)	cout<<sum[i]<<" ";
		cout<<endl<<"Prod : ";
		for(int i=0;i<=n;i++)	cout<<prod[i]<<" ";
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{
				if((sum[j]-sum[i-1])==(prod[j]/prod[i-1]))	cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
