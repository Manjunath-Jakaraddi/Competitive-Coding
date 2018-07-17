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
int main()
{
	prep();



  cnode *prev=start,*curr=start->next;
  while(!(n>prev->value&&n<curr->value))
  {
    prev=curr;
    curr=curr->next;
  }
  prev->next=new cnode();
  prev->value=n;
  prev->next->next=curr;
  return prev->next;


  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=i;j++)
      cout<<i<<(j!=i?"*":"\n");
  }
  for(int i=n;i<=1;i--)
  {
    for(int j=1;<=i;j++)
    {
      cout<<i<<" ";
    }
    cout<<"\n";
  }

  cout<<i<<" ";
  cout<<"\n";
  return 0;
}
