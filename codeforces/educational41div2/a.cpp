#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
int main()
{
  int n,q;
  cin>>n>>q;
  vi arr(n);
  for(int i=0;i<q;i++)
  {
    int x;
    cin>>x;
    arr[x-1]++;
  }
  int ans=*min_element(arr.begin(),arr.end());
  cout<<ans<<"\n";
	return 0;
}
