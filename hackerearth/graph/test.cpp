// #include<bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef pair<int, int> ii;
// typedef vector<ii> vii;
// typedef vector<int> vi;
// #define MOD 1000000007
// #define pb push_back
// #define pf printf
// #define sf scanf
// #define all(v) v.begin(), v.end()
// #define rep(i, s, e) for(auto i=s; i<=e; i++)
// #define loop(i, n) for(int i=0; i<n; i++)
// #define mp make_pair
// inline void prep()
// {
// 	cin.tie(0);
// 	cin.sync_with_stdio(0);
// }
// int in[100005],dc[100005],arr[100005];
// int main()
// {
//     prep();
//     int t,n;
//     cin>>t;
//     while(t--)
//     {
//         cin>>n;
//         rep(i,1,n)  cin>>arr[i];
//         in[1]=arr[1];
//         rep(i,2,n)  if(arr[i]>arr[i-1]) in[i]=arr[i]+in[i-1];
//                     else    in[i]=arr[i];
//         dc[n]=arr[n];
//         for(int i=n-1;i>=1;i--)
//             if(arr[i]>arr[i+1]) dc[i]=arr[i]+dc[i+1];
//             else    dc[i]=arr[i];
//         int mx=0;
//         rep(i,1,n)
//             mx=max(mx,in[i]+dc[i]-arr[i]);
//         cout<<mx<<"\n";
//
//     }
//     return 0;
// }
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
int main()
{
	prep();
	int arr[5]={2,1,5,3,6};
	vi mxhp(arr,arr+5);
	make_heap(all(mxhp),less<int>());
	cout<<mxhp.front()<<"\n";
	return 0;
}
