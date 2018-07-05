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
int count(int x,int n,int i)
{
    if(i>x||x<0)   return 0;
    if(x-pow(i,n)==0)
    {
      return 1;
    }
    int cnt1=-1,cnt2=-1;
    if(pow(i,n)<=x) cnt1=count(x-pow(i,n),n,i+1);
    cnt2=count(x,n,i+1);
    if(cnt1==-1)  return cnt2;
    return cnt1+cnt2;
}
int main()
{
	prep();
  cout<<count(100,2,1  )<<"\n";
	return 0;
}
