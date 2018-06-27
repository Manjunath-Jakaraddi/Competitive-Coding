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
int n;
int arr[200005];
int main()
{
	prep();
  cin>>n;
  set<int> st;
  map<int,int> mmap;
  loop(i,n)
  {
    cin>>arr[i];
    st.insert(arr[i]);
  }
  int mn_dist=st.size();
  st.clear();
  int j=0,res=0;
  loop(i,n)
  {
		j=max(i,j);
    while(j<n&&st.size()<mn_dist)
    {
      mmap[arr[j]]++;
      if(mmap[arr[j]]==1)  st.insert(arr[j]);
      j++;
    }
		if(mn_dist==st.size())	res+=(n-j+1);
		mmap[arr[i]]--;
		if(mmap[arr[i]]==0)	st.erase(st.find(arr[i]));
  }
  cout<<res<<"\n";
	return 0;
}
