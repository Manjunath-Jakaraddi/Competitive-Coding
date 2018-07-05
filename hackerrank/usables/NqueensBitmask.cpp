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
int n,cnt,DONE;
void NQueens(int row_mask,int ldiag,int rdiag)
{
  if(row_mask==DONE)
  {
    cnt++;
    return;
  }
  int posSpaces=(DONE&~(row_mask|ldiag|rdiag));
  while(posSpaces)
  {
    int currPos=(posSpaces&-posSpaces);
    posSpaces-=currPos;
    NQueens(row_mask|currPos,(ldiag|currPos)<<1,(rdiag|currPos)>>1);
  }
}
int main()
{
	prep();
  cin>>n;
  DONE=((1<<n)-1);
  NQueens(0,0,0);
  cout<<cnt<<"\n";
  return 0;
}
