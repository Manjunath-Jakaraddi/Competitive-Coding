#include<bits/stdc++.h>
using namespace std;
int arr[1025][1025];
int n;
bool isinvalid(int l,int r,int u,int b)
{
	return (l<0||r>=1024||u<0||b>=1024);
}
int recur(int l,int r,int u,int b,int val)
{
	if(isinvalid(l,r,u,b))	return val;
	if(l==r&&u==b)
	{
		arr[l][u]=val;
		return val+1;
	}
	val=recur(l,((l+r+1)/2)-1,u,((u+b+1)/2)-1,val);
	val=recur(l,((l+r+1)/2)-1,((u+b+1)/2),b,val);
	val=recur(((l+r+1)/2),r,u,((u+b+1)/2)-1,val);
	val=recur(((l+r+1)/2),r,((u+b+1)/2),b,val);
	return val;
}
void process()
{
	recur(0,63,0,63,1);
}
int main()
{
	process();
	cin>>n;
	int val=1<<n;
	for(int i=0;i<val;i++)
	{
		for(int j=0;j<val;j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
