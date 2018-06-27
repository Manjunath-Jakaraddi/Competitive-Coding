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
int arr[100005],BIT[100005];
void add(int i,int val)
{
  while(i<100005)
  {
    BIT[i]+=val;
    i+=(i&-i);
  }
}
int query(int i)
{
  int sm=0;
  while(i)
  {
    sm+=BIT[i];
    i-=(i&-i);
  }
  return sm;
}
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    fill(BIT,BIT+100000,0);
    cin>>n;
    int inv=0;
    loop(i,n) cin>>arr[i];
    bool ok=false;
    for(int i=n-1;i>=0;i--)
    {
      int z=query(arr[i]);
      cout<<arr[i]<<" "<<z<<"@\n";
      add(arr[i],1);
      if(z>2)
      {
        cout<<"To chaotic\n";
        ok=true;
        break;
      }
      inv+=z;
    }
    loop(i,10)  cout<<BIT[i]<<" ";
    if(!ok) cout<<inv<<"\n";
  }
	return 0;
}
