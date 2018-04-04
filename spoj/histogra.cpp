#include<bits/stdc++.h>
using namespace std;
int main()
{
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)	break;
		long long x,mx=0;
		stack<long long> st;
		vector<long long> v(n);
		int i;
		for(int i=0;i<n;i++)	cin>>v[i];
		for(i=0;i<n;)
		{
			if(st.empty()||v[st.top()]<=v[i])	st.push(i++);
			else
			{
					long long tp=st.top();
					st.pop();
					mx=max(mx,(v[tp]*(st.empty()?i:i-st.top()-1)));
			}
		}
		while(!st.empty())
		{
			long long tp=st.top();
			st.pop();
			mx=max(mx,(v[tp]*(st.empty()?i:i-st.top()-1)));
		}
		cout<<mx<<endl;
	}
}
