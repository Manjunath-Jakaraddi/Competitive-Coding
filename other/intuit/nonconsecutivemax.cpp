#include<bits/stdc++.h>
using namespace std;
int main()
{
	int arr[100];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)	cin>>arr[i];
	int incl=arr[0],excl=0,excl_new=0,mx=0;
	for(int i=1;i<n;i++)
	{
		excl_new=max(incl,excl);
		incl=excl+arr[i];
		excl=excl_new;
	}
	mx=max(incl,excl);
	cout<<mx<<endl;
}
