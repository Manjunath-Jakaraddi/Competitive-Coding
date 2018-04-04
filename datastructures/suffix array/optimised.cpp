#include<bits/stdc++.h>
using namespace std;
#define N 1000006
typedef struct
{
	int index;
	int rank[2];
}suffix;
int sai[N];
int lcp[N];
int cmp(suffix a,suffix b)
{
	return (a.rank[0]==b.rank[0])?(a.rank[1]<b.rank[1]?1:0):(a.rank[0]<b.rank[0]?1:0);
}

void buildSA(string txt)
{
	int n=txt.length();
	suffix suffixes[n];
	for(int i=0;i<n;i++)
	{
		suffixes[i].index=i;
		suffixes[i].rank[0]=txt[i]-'a';
		suffixes[i].rank[1]=((i+1)<n)?(txt[i+1]-'a'):-1;
	}
	sort(suffixes,suffixes+n,cmp);
	int ind[n];
	for(int k=4;k<2*n;k=k*2)
	{
		int rank=0;
		int prev_rank=suffixes[0].rank[0];
		suffixes[0].rank[0]=rank;
		ind[suffixes[0].index]=0;
		for(int i=1;i<n;i++)
		{
			if(suffixes[i].rank[0]==prev_rank&&suffixes[i].rank[1]==suffixes[i-1].rank[1])
			{
				prev_rank=suffixes[i].rank[0];
				suffixes[i].rank[0]=rank;
			}
			else
			{
				prev_rank=suffixes[i].rank[0];
				suffixes[i].rank[0]=++rank;
			}
			ind[suffixes[i].index]=i;
		}
		for(int i=0;i<n;i++)
		{
			int nextindex=suffixes[i].index+k/2;
			suffixes[i].rank[1]=(nextindex<n)?suffixes[ind[nextindex]].rank[0]:-1;
		}
		sort(suffixes,suffixes+n,cmp);
	}
	for(int i=0;i<n;i++)	sai[i]=suffixes[i].index;
}
void buildlcp(string s)
{
	int n=s.length();
	vector<int> invSuff(n,0);
	for(int i=0;i<n;i++)	invSuff[sai[i]]=i;
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(invSuff[i]==n-1)
		{
			k=0;
			continue;
		}
		int j=sai[invSuff[i]+1];
		while(i+k<n&&j+k<n&&s[i+k]==s[j+k])	k++;
		lcp[invSuff[i]]=k;
		if(k>0)	k--;
	}
}
int main()
{
	string s;
	cin>>s;
	buildSA(s);
	buildlcp(s);
	for(int i=0;i<s.length();i++)	cout<<sai[i]<<" "<<lcp[i]<<endl;
	return 0;
}
