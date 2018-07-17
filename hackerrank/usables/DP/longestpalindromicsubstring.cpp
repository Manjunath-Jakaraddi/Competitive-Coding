#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define pb push_back
#define pf printf
#define sf scanf
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(auto i=s; i<=e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
//		B A N A N A 	1) First fill all the diagonal as true one elements are paldromes
//	B T F F F F F   2) Fill consective same places same as palindrome second layer of he daiagonal on top
//	A 	T F T F T   3) begin search of 3 distance if matched check if two distance matached then consider and updated max and palind_begin
//	N 		T F T F
//	A				T F T
//	N					T F
//	A						T
int max_len=1,palin_begin=-1;
int lps[100][100];
string s1;
int n,m;
int bup()
{
	string ts1=" "+s1;
	for(int i=1;i<=n;i++)	lps[i][i]=1;// all single elements as palindrome
	for(int i=1;i<n;i++) if(ts1[i]==ts1[i+1])
	{
		lps[i][i+1]=1;
		palin_begin=i;
		max_len=2;
	}
	for(int curr=3;curr<=n;curr++)
	{
		for(int i=1;i<=n-curr+1;i++)
		{
			int j=i+curr-1;
			if(ts1[i]==ts1[j]&&lps[i+1][j-1])
			{
				lps[i][j]=1;
				palin_begin=i;
				max_len=curr;
			}
		}
	}
	cout<<"Length of Longest Palindromic Substring "<<ts1.substr(palin_begin,max_len)<<" is "<<max_len<<"\n";
}
string new_str;// In format $#a#b#a#b....@
// ($ ->Start 	@ -> End	#-> to find even length palindroms)
int C=0,R=0;	// C-> Center of Palindrome found and R is the right boundary
int LPS[202];	// To store the length of palindromes
void Manachars()
{
	new_str="$";
	for(char ch:s1)
	{
		new_str.pb('#');
		new_str.pb(ch);
	}
	new_str+="#@";
	cout<<new_str<<"\n";
	for(int i=1;i<new_str.length()-1;i++)
	{
		// Loop from first delimiter # to last #

		// 1) When the ith character lies in the Right Boundary of some prev palindrome
		// Update its minimum Length to that of its mirror
		int mirr=2*C-i;
		if(i<R)	LPS[i]=min(R-i,LPS[mirr]);

		// 2) Try and expand from the curr palindrome length LPS[i]
		while(new_str[i+(1+LPS[i])]==new_str[i-(1+LPS[i])])	LPS[i]++;

		// 3) Update the Center and Right Boundary if it expands across the right boundary
		if(i+LPS[i]>R)
		{
			C=i;
			R=i+LPS[i];
		}
	}
	rep(i,0,2*n+2)	cout<<LPS[i]<<" ";	cout<<"\n";
}
int main()
{
	prep();
	cin>>s1;
	n=s1.length();
	// bup();
	Manachars();
	return 0;
}
