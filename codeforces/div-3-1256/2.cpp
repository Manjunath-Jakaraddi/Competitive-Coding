#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		int n,k,x;
		cin>>n>>k;
		vector<int> arr;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			if(x&1)	arr.push_back(i+1);
		}
		if(arr.size()>=k)
		{
			cout<<"YES\n";
			for(int i=0;i<k-1;i++)	cout<<arr[i]<<" ";
			cout<<arr[arr.size()-1]<<"\n";
		}
		else
			cout<<"NO\n";
	}
}

