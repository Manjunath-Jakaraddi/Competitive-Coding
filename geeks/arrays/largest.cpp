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
  int t,n;
  string s[105];
  bool comp(string s1,string s2)
  {
    string XY=s1+s2;
    string YX=s2+s1;
    return XY.compare(YX)>0?true:false;
  }
  int main()
  {
  	prep();
    cin>>t;
    while(t--)
    {
      cin>>n;
      loop(i,n) cin>>s[i];
      sort(s,s+n,comp);
      loop(i,n) cout<<s[i];
      cout<<"\n";
    }
  	return 0;
  }
