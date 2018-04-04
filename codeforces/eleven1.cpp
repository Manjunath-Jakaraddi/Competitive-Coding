#include<bits/stdc++.h>
using namespace std;
bool fib[1001];
void fibonacci()
{
	int x=0,y=1,z=x+y;
	memset(fib,false,1001);
	fib[z]=true;
	do
	{
		x=y;
		y=z;
		z=x+y;
		fib[z]=true;
	}while(z<1001);
}
int main()
{
	fibonacci();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		if(fib[i])	cout<<"O";
		else		cout<<"o";
	return 0;
}
