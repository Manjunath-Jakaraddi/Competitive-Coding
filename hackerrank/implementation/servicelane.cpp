#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007


int arr[100005],n,q;
int main()
{
  cin>>n>>q;
  for(int i=0;i<n;i++)  cin>>arr[i];
  int x,y;
  while(q--)
  {
    cin>>x>>y;
    int mn=INT_MAX;
    for(int i=x;i<=y;i++) mn=min(mn,arr[i]);
    cout<<mn<<"\n";
  }
  return 0;
}
