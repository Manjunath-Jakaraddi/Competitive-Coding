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
int n,d;
ll arr[200005];
int freq[202];
int main()
{
	prep();
  int res=0;
  cin>>n>>d;
  loop(i,n) cin>>arr[i];
  loop(i,n)
  {
    if(i<d) freq[arr[i]]++;
    else
    {
      int med1=-1,med2=-1,sm=0;
      rep(i,0,200)
      {
        sm+=freq[i];
        if(med1==-1&&sm>=int(floor((d+1)/2.0))) med1=i;
        if(med2==-1&&sm>=int(ceil((d+1)/2.0)))  med2=i;
      }
      assert(sm==d);
      if((med1+med2)<=arr[i]) res++;
      freq[arr[i-d]]--;
      freq[arr[i]]++;
    }
  }
    // loop(i,n) freq[arr[i]]++;
    // loop(i,201) cout<<i<<" : "<<freq[i]<<"\n";
  cout<<res<<"\n";
	return 0;
}
