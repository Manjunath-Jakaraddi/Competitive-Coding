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
int n;
int board[10][10];
bool isSafe(int i,int j)
{
  // Search Column Up
  for(int k=0;k<i;k++)  if(board[k][j]) return false;
  // Search left diagonal Up
  int x=i,y=j;
  while(x>=0&&y>=0)
  {
    if(board[x][y])  return false;
    x--;y--;
  }
  x=i;y=j;
  while(x>=0&&y<n)
  {
    if(board[x][y]) return false;
    x--;y++;
  }
  return true;
}
bool NQueens(int row)
{
  if(row==n)
  {
    // print board
    loop(i,n)
    {
      loop(j,n)
      {
        if(board[i][j]) cout<<"Q ";
        else  cout<<"_ ";
      }
      cout<<"\n";
    }
    cout<<"\n\n\n";
    // return false; // False for Printing all the configuration existing
    return true; //True for checking if a configuration exists or not
  }
  loop(i,n)
  {
    if(isSafe(row,i))
    {
      board[row][i]=1;
      bool nextRowSolve=NQueens(row+1);
      if(nextRowSolve)  return true;
      board[row][i]=0;
    }
  }
  return false;
}
int main()
{
	prep();
  cin>>n;
  NQueens(0);
  return 0;
}
