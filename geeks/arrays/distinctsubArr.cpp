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
int t,n;
int arr[100005];
int main()
{
	prep();
  cin>>t;
  while (t--) {
    cin>>n;
    for(int i=0;i<n;i++)  cin>>arr[i];
    set<int> st;
    int j=0,ans=0;
    for(int i=0;i<n;i++)
    {
      while(j<n&&st.find(arr[j])==st.end())   st.insert(arr[j++]);
      ans+=((j-i)*(j-i+1))/2;
      st.erase(arr[i]);
    }
    cout<<ans<<"\n";
  }
  return 0;
}
