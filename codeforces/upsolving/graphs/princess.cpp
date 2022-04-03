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
int t, n, k, x;
// int findFirstAvailable(vector<int> arr, int mmap[]) {
//     for(int per : arr) {
//       if(!mmap[per]) {
//         return per;
//       }
//     }
//     return -1;
// }

int main()
{
	prep();
  cin>>t;
  // while(t--) {
  //   cin>>n;
  //   vector<int> adj[n];
  //   loop(i,n) {
  //     cin>>k;
  //     loop(j,k) {
  //       cin>>x;
  //       x--;
  //       adj[i].pb(x);
  //     }
  //   }
  //   int mmap[n];
  //   int unMatched = -1;
  //   memset(mmap, 0, sizeof(mmap));
  //   loop(i,n) {
  //     int firstAvailable = findFirstAvailable(adj[i], mmap);
  //     if(firstAvailable != -1) {
  //       mmap[firstAvailable]=1;
  //     }
  //     if(firstAvailable==-1 && unMatched == -1) {
  //       unMatched = i;
  //     }
  //   }
  //   if(unMatched == -1) {
  //     cout<<"OPTIMAL\n";
  //     continue;
  //   }
  //   cout<<"IMPROVE\n";
  //   loop(i,n) if(!mmap[i]) {
  //     cout<<unMatched+1<<" "<<i+1<<"\n";
  //     break;
  //   }
  // }

  while(t--) {
    cin>>n;
    vector<int>  ltaken(n), rtaken(n);
    loop(i, n) {
      cin>>k;
      loop(j,k) {
        cin>>x;
        x--;
        if(!ltaken[i] && !rtaken[x]) {
          ltaken[i]=rtaken[x]=true;
        }
      }
    }
    int a = int(find(ltaken.begin(), ltaken.end(), false) - ltaken.begin());
    int b = int(find(rtaken.begin(), rtaken.end(), false) - rtaken.begin());
    if(a==n) {
      cout<<"OPTIMAL\n";
      continue;
    }
    cout<<"IMPROVE\n";
    cout<<a+1<<" "<<b+1<<"\n";
  }
	return 0;
}
