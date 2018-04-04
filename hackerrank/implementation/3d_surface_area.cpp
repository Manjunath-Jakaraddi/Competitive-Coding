#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int cube[101][101];
int dir[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int main()
{
  int m,n;
  cin>>m>>n;
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      cin>>cube[i][j];
  int area=2*m*n;
  for(int i=1;i<=m;i++)
  {
    for(int j=1;j<=n;j++)
    {
      for(int k=0;k<4;k++)
      {
        int a=cube[i][j]-cube[i+dir[k][0]][j+dir[k][1]];
        if(a>0) area+=a;
      }
    }
  }
  cout<<area<<"\n";
  return 0;
}
