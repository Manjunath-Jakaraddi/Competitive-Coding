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
int na,nb,nc;
int a[100],b[100],c[100];
int main()
{
	prep();
  cin>>na>>nb>>nc;
  loop(i,na)  cin>>a[i];
  loop(i,nb)  cin>>b[i];
  loop(i,nc)  cin>>c[i];
  int mn_range=INT_MAX;
  int i=0,j=0,k=0;
  while(i<na&&j<nb&&k<nc)
  {
    int f=a[i],s=b[j],t=c[k];
    mn_range=min(mn_range,max(f,max(s,t))-min(f,min(s,t)));
    if(f<=s&&f<=t)  i++;
    else if(s<t&&s<f)  j++;
    else if(t<f&&t<s) k++;
  }
  cout<<mn_range<<"\n";
	return 0;
}
