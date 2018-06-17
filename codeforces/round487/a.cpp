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
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
bool check(char x,char y,char z)
{
  char arr[3]={x,y,z};
  sort(arr,arr+3);
  if(arr[1]==arr[0]+1&&arr[2]==arr[0]+2) return true;
  return false;
}
bool valid(char ch)
{
  if(ch>='A'&&ch<='C')  return true;
  return false;
}
int main()
{
	prep();
  string s;
  cin>>s;
  int n=s.length();
  bool ok=false;
  if(n<2)
  {
    cout<<"No\n";
    return 0;
  }
  loop(i,n-2)
  {
    if(valid(s[i])&&valid(s[i+1])&&valid(s[i+2])&&check(s[i],s[i+1],s[i+2]))
    {
      ok=true;
      cout<<"Yes\n";
      break;
    }
  }
  if(!ok) cout<<"No\n";
  return 0;
}
