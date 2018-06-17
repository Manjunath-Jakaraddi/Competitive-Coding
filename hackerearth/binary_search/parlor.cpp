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
int arr[50005];
int main()
{
	prep();
  int t,n,sm,x;
  cin>>t;
  while(t--)
  {
    cin>>sm>>n;
    map<int,int> mmap;
    loop(i,n)
    {
      cin>>arr[i];
      mmap[arr[i]]=i+1;
    }
    loop(i,n)
      if(mmap[sm-arr[i]])
      {
          cout<<i+1<<" "<<mmap[sm-arr[i]]<<"\n";
          break;
      }
  }
  return 0;
}
