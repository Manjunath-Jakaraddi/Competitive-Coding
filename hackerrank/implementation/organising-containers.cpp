#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int arr[101][101]={{0}};
    int n,q;
    cin>>n;
    int row[101]={0},col[101]={0};
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>arr[i][j];
        row[i]+=arr[i][j];
        col[j]+=arr[i][j];
      }
    }
    bool ok=true;
    int i,j;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        if(row[i]==col[j])
        {
          swap(col[i],col[j]);
          break;
        }
      }
      if(j==n)
      {
        ok=false;
        break;
      }
    }
    ok?(cout<<"Possible\n"):(cout<<"Impossible\n");
  }
  return 0;
}

// SOLUTION 2
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int arr[101][101]={{0}};
    int n,q;
    cin>>n;
    int row[101]={0},col[101]={0};
    for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        cin>>arr[i][j];
        row[i]+=arr[i][j];
        col[j]+=arr[i][j];
      }
    }
    int i;
    sort(row,row+n);
    sort(col,col+n);
    for(i=0;i<n;i++)    if(row[i]!=col[i])    break;
    i==n?(cout<<"Possible\n"):(cout<<"Impossible\n");
  }
  return 0;
}
