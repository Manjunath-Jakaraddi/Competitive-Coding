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
ll n,k;
vi arr;
set<int> st;
map<int,int> mmap;
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int main()
{
	prep();
  cin>>n>>k;
  arr.assign(n,0);
  loop(i,n)
  {
    cin>>arr[i];
    mmap[arr[i]]++;
    st.insert(arr[i]);
  }
  vi arr2(all(st));
  sort(all(arr2));
  int cur=arr2[(int)arr2.size()-1];
  ll ans=mmap[cur];
  for(int i=arr2.size()-2;i>=0;i--)
  {
    if(arr2[i]+k>=cur)
      cur=arr2[i];
    else
    {
      ans+=mmap[arr2[i]];
      cur=arr2[i];
    }
  }
  cout<<ans<<"\n";
  return 0;
}
