#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int m,n;
char str[202][202],str2[202][202],str3[202][202];
int main()
{
  int t;
  cin>>m>>n>>t;
  cout<<t;
  for(int i=0;i<m;i++)  cin>>str[i];
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      str2[i][j]='O';
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      str3[i][j]='O';
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(str[i][j]=='O')
      {
        str2[i][j]='.';
        if(i<m-1) str2[i+1][j]='.';
        if(i>0)   str2[i-1][j]='.';
        if(j<n-1) str2[i][j+1]='.';
        if(j>0)   str2[i][j-1]='.';
      }
    }
  }
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(str2[i][j]=='O')
      {
        str3[i][j]='.';
        if(i<m-1) str3[i+1][j]='.';
        if(i>0)   str3[i-1][j]='.';
        if(j<n-1) str3[i][j+1]='.';
        if(j>0)   str3[i][j-1]='.';
      }
    }
  }
  if(t==1||t==0)
  {
    for(int i=0;i<m;i++)  cout<<str[i]<<"\n";
    return 0;
  }
  if((t-1)%2==0&&(t-1)%4!=0)
  {
    for(int i=0;i<m;i++)  cout<<str2[i]<<"\n";
  }
  else if((t-1)%4==0)
  {
    for(int i=0;i<m;i++)  cout<<str3[i]<<"\n";
  }
  else if(t%2==0)
  {
    for(int i=0;i<m;i++)
    {
      for(int j=0;j<n;j++)
      {
        cout<<"O";
      }
      cout<<"\n";
    }
  }

  return 0;
}
