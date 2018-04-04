#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int n,m,top,score,stk[100005];

int main()
{
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>stk[top+1];
    if(stk[top]!=stk[top+1])  ++top;
  }
  cin>>m;
  for(int i=0;i<m;i++)
  {
    cin>>score;
    while(top&&score>=stk[top]) top--;
    cout<<top+1<<"\n";
  }
  return 0;
}
