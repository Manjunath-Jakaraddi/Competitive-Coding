#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int n,a,b;
    cin>>n>>a>>b;
    int first=(n-1)*min(a,b);
    cout<<first<<" ";
    int sm=0;
    while(first+sm<(n-1)*max(a,b))
    {
      sm+=abs(b-a);
      cout<<first+sm<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
