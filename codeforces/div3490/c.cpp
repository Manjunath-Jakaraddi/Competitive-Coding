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
int arr[26];
int n,k;
string s;
int main()
{
	prep();
  cin>>n>>k>>s;
  for(char ch:s)  arr[ch-'a']++;
  for(int i=0;i<26;i++)
    if(arr[i])
    {
      if(arr[i]>k)
      {
        arr[i]-=k;
        k=0;
      }
      else
      {
        k-=arr[i];
        arr[i]=0;
      }
    }
  // loop(i,26)  cout<<arr[i]<<" ";
  string res="";
  for(int i=n-1;i>=0;i--)
  {
    if(arr[s[i]-'a']>0)
    {
      res.pb(s[i]);
      arr[s[i]-'a']--;
    }
  }
  reverse(all(res));
  cout<<res<<"\n";
	return 0;
}
