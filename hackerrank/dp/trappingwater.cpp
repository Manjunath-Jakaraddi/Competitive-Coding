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
int q,n,x;
bitset<10000> bs;
void sieve()
{
  bs.set();
  bs[0]=bs[1]=0;
  for(int i=2;i<10000;i++)  if(bs[i])
  {
    for(int j=i+i;j<10000;j+=i)  bs[j]=0;
  }
}
int main()
{
	prep();
  sieve();
  cin>>q;
  while(q--)
  {
    cin>>n;
    vector<vector<ll>> dp;
    set<ll> s;
    vector<ll> st;
    ll cnt[8200]={0};
    loop(i,n)
    {
      cin>>x;
      cnt[x]++;
      s.insert(x);
    }
    n=s.size();
    for(auto it:s)  st.pb(it);
    dp.assign(n+1,vector<ll>(8200,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<=8192;j++)
      {
        cnt[st[i-1]]%=MOD;
        dp[i][j]=
                ((dp[i-1][j]*((cnt[st[i-1]]+2)/2))%MOD
                +(dp[i-1][j^st[i-1]]*((cnt[st[i-1]]+1)/2))%MOD)
                %MOD;
      }
    }
    ll res=0;
    for(int i=0;i<=8192;i++)
      if(bs[i]) res=(res+dp[n][i])%MOD;
    cout<<res<<"\n";
  }
	return 0;
}
