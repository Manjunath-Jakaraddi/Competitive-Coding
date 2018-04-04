#include<iostream>
using namespace std;
int a[100];
int main()
{
	lo n,ans;
	cin>>n>>a[1];
	ans=0;
	for(int i=2;i<=n;i++)
	{
		a[i]+=(a[i-1]+a[i-2]);
	}
	for(int i=1;i<=n;i++)	ans+=a[i];
	cout<<ans;
	return 0;
}
