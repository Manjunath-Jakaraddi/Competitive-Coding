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
int arr[2002],arr2[2002];
bool is_sorted(int ar[]) {
  loop(i,2*n-1) if(ar[i] > ar[i+1]) return false;
  return true;
}
int main()
{
	prep();
  cin>>n;
  loop(i, 2*n) {
    cin>>arr[i];
    arr2[i]=arr[i];
  }
  if(is_sorted(arr)) {
    cout<<0<<endl;
    return 0;
  }
  bool tog = true;
  int res = 0;
  for(int i=0; i<2*n; i++) {
    if(tog) {
      for(int i=0; i<2*n; i+=2) {
        int temp = arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
      }
    } else {
      for(int i=0; i<n; i++) {
        int temp = arr[i];
        arr[i]=arr[n+i];
        arr[n+i]=temp;
      }
    }
    res++;
    tog=!tog;
    if(is_sorted(arr)) break;
  }
  tog=false;
  int res2=0;
  for(int i=0; i<2*n; i++) {
    if(tog) {
      for(int i=0; i<2*n; i+=2) {
        int temp = arr2[i];
        arr2[i]=arr2[i+1];
        arr2[i+1]=temp;
      }
    } else {
      for(int i=0; i<n; i++) {
        int temp = arr2[i];
        arr2[i]=arr2[n+i];
        arr2[n+i]=temp;
      }
    }
    res2++;
    tog=!tog;
    if(is_sorted(arr2)) break;
  }
  bool is_sorted_arr = is_sorted(arr), is_sorted_arr2 = is_sorted(arr2);
  if(is_sorted_arr && is_sorted_arr2) {
    cout<<min(res, res2)<<endl;
  }
  else if(!is_sorted_arr && !is_sorted_arr2) {
    cout<<"-1"<<endl;
  }
  else cout<<(is_sorted_arr ? res : res2)<<endl;
	return 0;
}
