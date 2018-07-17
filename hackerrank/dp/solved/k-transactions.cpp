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
int price[100];
int T[100][100];
int n,k;
int bup() // O(n^2*K)
{
  for(int i=1;i<=k;i++)
  {
    for(int j=1;j<n;j++)
    {
      T[i][j]=T[i][j-1];
      for(int m=0;m<j;m++)
      {
        T[i][j]=max(T[i][j],T[i-1][m]+price[j]-price[m]);
      }
    }
  }
  // for(int i=1;i<=k;i++)
  // {
  //   for(int j=1;j<n;j++)
  //   {
  //     cout<<T[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  return T[k][n-1];
}
int optimised_bup() // O(nK)
{
  for(int i=1;i<=k;i++)
  {
    int maxdiff=T[i-1][0]-price[0];
    for(int j=1;j<n;j++)
    {
      maxdiff=max(maxdiff,T[i-1][j]-price[j]);
      T[i][j]=max(T[i][j-1],price[j]+maxdiff);
    }
  }
  // for(int i=1;i<=k;i++)
  // {
  //   for(int j=1;j<n;j++)
  //   {
  //     cout<<T[i][j]<<" ";
  //   }
  //   cout<<"\n";
  // }
  return T[k][n-1];
}
int main()
{
	prep();
  cin>>n>>k;
  loop(i,n) cin>>price[i];
  cout<<optimised_bup()<<"\n";
	return 0;
}
