#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int n1,m1,k;
int arr[400][400];
void rotatematrix()
{
  int n=n1,m=m1;
  int row=1,col=1;
  int prev,curr;
  while(row<=m&&col<=n)
  {
    if(row==m||col==n)  break;
    // prev=arr[row+1][col];
    prev=arr[row][col+1];
    for(int i=row;i<=m;i++)
    {
      curr=arr[i][col];
      arr[i][col]=prev;
      prev=curr;
    }
    col++;
    // for(int i=col;i<=n;i++)
    // {
    //   curr=arr[row][i];
    //   arr[row][i]=prev;
    //   prev=curr;
    // }
    // row++;
    for(int i=col;i<=n;i++)
    {
      curr=arr[m][i];
      arr[m][i]=prev;
      prev=curr;
    }
    m--;
    // for(int i=row;i<=m;i++)
    // {
    //   curr=arr[i][n];
    //   arr[i][n]=prev;
    //   prev=curr;
    // }
    // n--;
    if(col<=n)
    {
      for(int i=m;i>=row;i--)
      {
        curr=arr[i][n];
        arr[i][n]=prev;
        prev=curr;
      }
    }
    n--;
    // if(row<=m)
    // {
    //   for(int i=n;i>=col;i--)
    //   {
    //     curr=arr[m][i];
    //     arr[m][i]=prev;
    //     prev=curr;
    //   }
    // }
    // m--;
    if(row<=m)
    {
      for(int i=n;i>=col;i--)
      {
        curr=arr[row][i];
        arr[row][i]=prev;
        prev=curr;
      }
    }
    row++;
    // if(col<=n)
    // {
    //   for(int i=m;i>=row;i--)
    //   {
    //     curr=arr[i][col];
    //     arr[i][col]=prev;
    //     prev=curr;
    //   }
    // }
    // col++;
  }
}
int main()
{
  cin>>m1>>n1>>k;
  for(int i=1;i<=m1;i++)
    for(int j=1;j<=n1;j++)
      cin>>arr[i][j];
  int z=(m1+n1)*2-min(m1,n1)*4;
  if(z) k=k%z;
  for(int i=0;i<k;i++)  rotatematrix();
  for(int i=1;i<=m1;i++)
  {
    for(int j=1;j<=n1;j++)
    {
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
  return 0;
}
