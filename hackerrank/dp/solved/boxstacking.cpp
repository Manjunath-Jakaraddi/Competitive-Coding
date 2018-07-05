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
int l,w,h,n;
class dim
{
  public:
  int l,w,h;
  dim(int a,int b,int c)  { l=a;w=b;h=c; }
};
vector<pair<int,dim>> arr;
vi dp,onTopOf;
bool comp(pair<int,dim> a,pair<int,dim> b)
{
  return a.first<b.first;
}
void printBox(int res)
{
  cout<<arr[res].second.l<<" "<<arr[res].second.w<<" "<<arr[res].second.h<<"\n";
  if(onTopOf[res]==res) return ;
  printBox(onTopOf[res]);
}
int main()
{
	prep();
  cin>>n;
  ll res=0,resind=-1;
  dp.assign(3*n,0);
  onTopOf.assign(3*n,0);
  loop(i,n)
  {
    cin>>l>>w>>h;
    arr.pb({l*w,dim(l,w,h)});
    arr.pb({l*h,dim(l,h,w)});
    arr.pb({w*h,dim(w,h,l)});
  }
  sort(all(arr),comp);
  reverse(all(arr));
  for(auto it:arr)  cout<<it.second.h<<"\n";
  loop(i,3*n)
  {
    dp[i]=arr[i].second.h;
    onTopOf[i]=i;
  }
  for(int i=1;i<3*n;i++)
  {
    for(int j=0;j<i;j++)
    {
      int l1=arr[i].second.l,l2=arr[j].second.l;
      int w1=arr[i].second.w,w2=arr[j].second.w;

      if(max(l1,w1)<max(l2,w2)&&min(l1,w1)<min(l2,w2))
      {
        if(dp[i]<dp[j]+arr[i].second.h)
        {
          dp[i]=dp[j]+arr[i].second.h;
          onTopOf[i]=j;
          if(res<dp[i])
          {
            res=dp[i];
            resind=i;
          }
        }
      }
    }
  }
  cout<<"Height of the highest Stack : "<<res<<"\n";
  cout<<"Boxes : ";
  printBox(resind);
	return 0;
}
