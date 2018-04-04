#include<bits/stdc++.h>
using namespace std;
int arr[100],n;
int binary_search(int x,int l,int r)
{
	if(l<=r)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]==x)	return mid;
		else if(x<arr[mid])	return binary_search(x,l,mid-1);
		else return binary_search(x,mid+1,r);

	}
}
int shifted()
{
	int pivot=0;
	for(int i=1;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			pivot=i-1
		}
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)	cin>>arr[i];
	return 0;
}
