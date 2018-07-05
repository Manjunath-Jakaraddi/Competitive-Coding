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
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int n;
int arr[100],lis[100];
void bup()
{
	for(int i=1;i<n;i++)
		for(int j=0;j<i;j++)
			if(arr[i]>arr[j]) lis[i]=max(lis[i],1+lis[j]);
	cout<<*max_element(lis,lis+n)<<"\n";
}
// Optimised Method
int parent[100],LIS[100];
vi increasing;
int insertInPlace(int x)
{
	if(increasing.size()==0)	increasing.pb(x);
	auto it=lower_bound(all(increasing),x);
	if(it==increasing.end())	increasing.pb(x);
	int ind=it-increasing.begin();
	increasing[ind]=x;
}
void Optimised()
{
	loop(i,n)	insertInPlace(arr[i]);
	for(auto it:increasing)	cout<<it<<" ";	cout<<"\n";
}
int main()
{
	prep();
  cin>>n;
  loop(i,n)
  {
    cin>>arr[i];
    lis[i]=1;
  }
	bup();
	Optimised();
  return 0;
}
