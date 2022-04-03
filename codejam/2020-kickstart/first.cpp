#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int main()
{
	prep();
  int t;
  cin>>t;
  for(int k=0; k<t; k++) {
    int n, wt;
    cin>>n>>wt;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    sort(arr.begin(), arr.end());
    int cnt=0;
    while(cnt<n&&arr[cnt]<=wt) {
      wt-=arr[cnt];
      cnt++;
    }
    cout<<"Case #"<<k+1<<": "<<cnt<<"\n";
  }
	return 0;
}
