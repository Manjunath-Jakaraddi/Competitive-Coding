#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
string arr[1001],pat[1001];
int M,N,m,n;
bool search(int x1,int y1)
{
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(arr[x1+i][y1+j]-pat[i][j]!=0)  return false;
  return true;
}
string solve()
{
  for(int i=0;i<M-m+1;i++)
    for(int j=0;j<N-n+1;j++)
        if(search(i,j))  return "YES";
  return "NO";
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    cin>>M>>N;
    for(int i=0;i<M;i++)  cin>>arr[i];
    cin>>m>>n;
    for(int i=0;i<m;i++)  cin>>pat[i];
    cout<<solve()<<"\n";
  }
  return 0;
}
