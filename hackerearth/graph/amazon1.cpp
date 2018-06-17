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
#define rep(i, s, e) for(auto i=s; i<e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int cut[200005];
int L,R,t,x,y,n;
int solve(int llng,int rlng,int L,int R,int ind)
{
  if(L>=R)  return 0;
  int cost=(x*(cut[ind]-llng)+y*(rlng-cut[ind]));
  cost+=solve(llng,cut[ind],L,ind-1,(L+ind-1)/2+1)+solve(cut[ind],rlng,ind+1,R,(ind+1+R)/2);
  return cost;
}
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    cin>>x>>y;
    cin>>n;
    loop(i,n) cin>>cut[i];
    sort(cut,cut+n);
    cout<<solve(cut[0],cut[n-1],0,n-1,n/2)<<"\n";
  }
  return 0;
}
