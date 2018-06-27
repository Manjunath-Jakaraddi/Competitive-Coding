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
int arr[1000006];
ll b[1000006];
int main()
{
	prep();
  map<ll,ll> mmap,freq;
  // mmap(ele,cnt)  freq(freq,cnt)
  cin>>n;
  loop(i,n) cin>>arr[i];
  loop(i,n) cin>>b[i];
  loop(i,n)
  {
    if(arr[i]==1)
    {
      // Insert
      freq[mmap[b[i]]]--;
      mmap[b[i]]++;
      freq[mmap[b[i]]]++;
    }
    else if(arr[i]==2)
    {
      // delete
      if(mmap[b[i]])
      {
        freq[mmap[b[i]]]--;
        mmap[b[i]]--;
        freq[mmap[b[i]]]++;
      }
    }
    else if(arr[i]==3)
    {
      // display with freq b[i]
      if(freq[b[i]]>0)  cout<<"1\n";
      else  cout<<"0\n";
    }
  }
	return 0;
}
