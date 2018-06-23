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
int t,n,k;
int arr[202];
int search_pivot(int l,int r)
{
  while(l<=r)
  {
    int mid=l+(r-l)/2;
    if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])  return mid;
    else if(arr[mid]>arr[mid-1]) l=mid+1;
    else  r=mid-1;
  }
  return -1;
}
int binarysearchasc(int l,int r)
{
  while(l<=r)
  {
    int mid=l+(r-l)/2;
    if(arr[mid]==k) return mid;
    else if(arr[mid]<k) l=mid+1;
    else  r=mid-1;
  }
  return -1;
}
int binarysearchdsc(int l,int r)
{
  while(l<=r)
  {
    int mid=l+(r-l)/2;
    if(arr[mid]==k) return mid;
    else if(arr[mid]>k) l=mid+1;
    else  r=mid-1;
  }
  return -1;
}
int main()
{
	prep();
  cin>>t;
  while(t--)
  {
    cin>>n>>k;
    arr[n+1]=INT_MAX;
    loop(i,n) cin>>arr[i+1];
    int pivot=search_pivot(1,n);
    if(pivot==-1) if((pivot=binarysearchasc(1,n))==-1)
                  cout<<"OOPS! NOT FOUND\n";
                  else  cout<<pivot-1<<"\n";
    else if(arr[pivot]==k)  cout<<pivot<<"\n";
    else
    {
      int ascfind=binarysearchasc(1,pivot-1);
      int descfind=binarysearchdsc(pivot,n);
      if(ascfind!=-1) cout<<ascfind-1<<"\n";
      else if(descfind!=-1) cout<<descfind-1<<"\n";
      else  cout<<"OOPS! NOT FOUND\n";
    }
  }
	return 0;
}
