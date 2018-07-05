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
int leftSmall[1000006],rightSmall[1000006],arr[1000006],res[1000006];
int n;
stack<int> st;
void findLeftSmallerElements()
{
  for(int i=0;i<n;i++)
  {
    while(!st.empty()&&arr[i]<=arr[st.top()])  st.pop();
    if(!st.empty()) leftSmall[i]=st.top();
    st.push(i);
  }
  // rep(i,0,n-1)  cout<<leftSmall[i]<<" ";  cout<<"\n";
  while(!st.empty()) st.pop();
}
void findRightSmallerElements()
{
  for(int i=n-1;i>=0;i--)
  {
    while(!st.empty()&&arr[i]<=arr[st.top()]) st.pop();
    if(!st.empty()) rightSmall[i]=st.top();
    st.push(i);
  }
  // rep(i,0,n-1)  cout<<rightSmall[i]<<" "; cout<<"\n";
}
void findWindow()
{
  int windSize;
  loop(i,n)
  {
    windSize=rightSmall[i]-leftSmall[i]-1;
    res[windSize]=max(res[windSize],arr[i]);
  }
  // Update the empty as the res[i] is always greater than or equal to res[i+1]
  // that is smaller windows max value is always greater than equal to larger windows
  for(int i=n-1;i>=1;i--) res[i]=max(res[i],res[i+1]);
}
int main()
{
	prep();
  cin>>n;
  loop(i,n)
  {
    cin>>arr[i];
    leftSmall[i]=-1;
    rightSmall[i]=n;
  }
  findLeftSmallerElements();
  findRightSmallerElements();
  findWindow();
  rep(i,1,n)  cout<<res[i]<<" ";  cout<<"\n";
  return 0;
}
