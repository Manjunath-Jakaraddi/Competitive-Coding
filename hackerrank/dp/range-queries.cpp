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
int t,q;
ll l,r;
set<ll> st;
vector<ll> res;
ll one=1;
void preprocess()
{
  for(int i=0;i<=60;i++)
  {
    for(int j=0;j<=60;j++)
    {
      for(int k=0;k<=60;k++)
      {
        st.insert((one<<i)|(one<<j)|(one<<k));
      }
    }
  }
  for(auto it:st) res.pb(it);
}
void process()
{
  set<ll> s;
  for (int i = 0; i <= 60; i++) {
        for (int j = i; j <= 60; j++) {
            for (int k = j; k <= 60; k++) {
                // 1 set bit
                if (j == i && i == k)
                    s.insert(1LL << i);

                // 2 set bits
                else if (j == k && i != j) {
                    ll x = (1LL << i) + (1LL << j);
                    s.insert(x);
                }
                else if (i == j && i != k) {
                    ll x = (1LL << i) + (1LL << k);
                    s.insert(x);
                }
                else if (i == k && i != j) {
                    ll x = (1LL << k) + (1LL << j);
                    s.insert(x);
                }

                // 3 set bits
                else {
                    ll x = (1LL << i) + (1LL << j) + (1LL << k);
                    s.insert(x);
                }
            }
        }
    }
    cout<<s.size()<<"\n";
}
int main()
{
	prep();
  cin>>t;
  preprocess();
  process();
  cout<<res.size()<<"\n";
  // while(t--)
  // {
  //   ll ans;
  //   cin>>l>>r;
  //   if(l>r) swap(l,r);
  //   if(l==0)  ans=upper_bound(all(res),r)-res.begin();
  //   else  ans=upper_bound(all(res),r)-lower_bound(all(res),l);
  //   cout<<ans<<"\n";
  // }
	return 0;
}
