#include<bits/stdc++.h>
using namespace std;
int arr[2000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,q,tap,mx=0,mxele=0;
		cin>>n>>q;
		for(int i=1;i<=q;i++)	cin>>arr[i];
		arr[q+1]=n+1;
		sort(arr+1,arr+q+2);
		for(int i=1;i<=q+1;i++)	
		{
			cout<<arr[i]<<" ";
			mx=max(mx,arr[i]-arr[i-1]);
		}
		cout<<mx<<endl;
	}
	return 0;
}
