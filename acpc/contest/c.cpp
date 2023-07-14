#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
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
// int main()
// {
//     prep();
//     string cows;
//     int ct=0;int a=1;
//     cin>>cows;
//     int n=cows.size();
//     vector<int> track(n,0);
//     for(int i=0;i<n-2;i++)
//     {
//         if(cows[i]=='c'&&cows[i+1]=='o'&&cows[i+2]=='w'&&i!=0&&i+2!=n-1)
//         {
//             ct++;
//             track[a]=i;
//             a++;

//         }
//     }

//     int j=1;
//     while(track[j+1]!=0)
//     {
//      if(track[j+1]-track[j]==3)
//      {
//         ct=ct-2;
//      }
//      j++;

//     }
//     cout<<ct<<"\n";

    
// 	return 0;
// }

int main() {
    string s;
    cin >>s;
    int n = s.length();
    vector<bool> iscow(n+1);
    int ans = 0;
    iscow[2] = (s.substr(0, 3) == "cow");
    for (int i=3; i<n-1; i++) {
        if (s.substr(i-3+1, 3) == "cow") {
            iscow[i] = true;
            ans++;
        }
        if (iscow[i] && iscow[i-3] && i >= 6 && iscow[i-6]) {
            ans--;
        }
        else if (iscow[i] && iscow[i-3]) {
            ans-=2;
        }
    }
    cout << max(0, ans) << "\n";
}