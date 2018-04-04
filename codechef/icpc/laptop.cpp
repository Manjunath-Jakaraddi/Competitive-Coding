#include<bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int n,k,x;
	cin>>k;
	while(k--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>x;
			a[x]++;
		}
		int i;
		for(i=0;i<101;i++)
		{
			if(a[i]==1)	break;
		}
		cout<<i<<endl;
		memset(a,0,101*sizeof(int));
	}
	return 0;
}
