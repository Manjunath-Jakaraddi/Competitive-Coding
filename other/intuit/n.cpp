//*3+5
#include<bits/stdc++.h>
using namespace std;
int n;
bool solve(int n)
{
	bool ok1=false,ok2=false;
	if(n==1)	return true;
	if(n%3==0)	ok1=solve(n/3);
	if(n-5>0)	ok2=solve(n-5);
	return ok1||ok2;
}
int main()
{
	cin>>n;
	if(solve(n))
		cout<<"YES"<<endl;
	return 0;
}
