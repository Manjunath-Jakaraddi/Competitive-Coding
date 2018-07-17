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
string s;
bitset<1000> bs;
vi primes;
void find_primes()
{
  bs.set();
  for(int i=2;i<=1000;i++)  if(bs[i])
  {
    for(int j=i+i;j<=1000;j+=i)  bs[j]=0;
    primes.pb(i);
    if(primes.size()==26) return;
  }
}
string compress(string s)
{
  int i=0,j=0,len=1;
  string temp=s,res="";
  while(len<=temp.length()/2)
  {
    int hash1=1,hash2=1;
    for(i=0;i<len;i++)  hash1*=primes[temp[i]-'a'];
    for(j=i;j<i+len;j++)  hash2*=primes[temp[j]-'a'];
    cout<<hash1<<" "<<hash2<<"\n";
    i--;j--;
    while(j<temp.length())
    {
      if(hash1==hash2)
      {
        res+=temp.substr(i-len+1,len);
        cout<<res<<"@";
        do
        {
          hash2=1;
          for(int k=j;k<j+len&&(j+len<temp.length());k++)  hash2*=primes[temp[k]-'a'];
          j+=len;
        }while(hash1==hash2);
      }
      else
      {
        res.pb(temp[i]);
        i++;
        hash1/=primes[temp[i-len]-'a'];
        hash1*=primes[temp[i]-'a'];
        j++;
        hash2/=primes[temp[j-len]-'a'];
        if(j<temp.length()) hash2*=primes[temp[j]-'a'];
      }
    }
    while(i+len-1<temp.length())  res.pb(temp[i++]);
    len++;
    temp=res;
    cout<<res<<"\n";
    res="";
  }
  return temp;
}
bool comp(string temp,int st1,int st2,int len)
{
  cout<<temp<<" "<<st1<<" "<<st2<<" "<<len<<"\n";
  for(int i=0;i<len;i++)  if(temp[st1+i]!=temp[st2+i])  return false;
  return true;
}
string brute(string s)
{
  string temp=s,res="";
  for(int len=1;len<=s.length()/2;len++)
  {
    int j=0;
    while(j+2*len<=temp.length())
    {
      res+=temp.substr(j,len);
      if(j+2*len<temp.length())
        while(j+2*len<temp.length()&&temp.substr(j,len)==temp.substr(j+len,len))
        {
          cout<<temp.substr(j,len)<<"@"<<temp.substr(j+len,len)<<"\n";
          j+=len;
        }
      else j++;
    }
    temp=res;
    if(len>temp.length()/2)  return temp;
    res="";
  }
  return temp;
}
int main()
{
	prep();
  find_primes();
  cin>>s;
  cout<<brute(s)<<"\n";
	return 0;
}
