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
int arr[2][202];
int main()
{
	prep();
  int c,k,l;
  cin>>c>>k;
  l=2*c;
  loop(i,c) cin>>arr[0][i];
  loop(i,c) cin>>arr[1][i];
  loop(i,c) cin>>arr[0][i+c];
  loop(i,c) cin>>arr[1][i+c];
  loop(i,l) if(arr[0][i]&&arr[0][i]==arr[1][i])
  {
    cout<<arr[0][i]<<" ";
    if(i/c==0)  cout<<"1 "<<i%c+1<<"\n";
    else  cout<<"4 "<<i%c+1<<"\n";
  }
  return 0;
}
