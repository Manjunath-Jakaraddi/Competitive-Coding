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
bool isSubsequence(string s,string t)
{
  map<char,set<int>> mmap;
  for(int i=0;i<t.length();i++)
  {
    if(mmap.find(t[i])==mmap.end())  mmap[t[i]]=(set<int>());
    mmap[t[i]].insert(i);
  }
  auto prev=-1;
  for(char c:s)
  {
    if(mmap.find(c)==mmap.end()||mmap[c].size()==0) return false;
    auto idx=lower_bound(mmap[c].begin(),mmap[c].end(),prev);
    if(idx==mmap[c].end()) return false;
    prev=*idx;
    mmap[c].erase(idx);
  }
  return true;
}
vector<vi> CountTrip(vector<int> &nums)
{
  vector<vector<int>> res;
  sort(nums.begin(),nums.end());
  int n=nums.size();
  for(int i=0;i<n;i++)
  {
    int target=-nums[i];
    int front=i+1;
    int back=n-1;
    while(front<back)
    {
      int sum=nums[front]+nums[back];
      if(sum>target)  back--;
      else if(sum<target) front++;
      else
      {
        vector<int> tmp({nums[i],nums[front],nums[back]});
        res.push_back(tmp);
        while(front<back&&nums[front]==tmp[1])  front++;
        while(front<back&&nums[back]==tmp[2]) back--;
      }
    }
    while(i+1<n&&nums[i+1]==nums[i])  i++;
  }
  return res;
}
int main()
{
	prep();
  vi nums;
  int n;
  cin>>n;
  nums.assign(n,0);
  loop(i,n) cin>>nums[i];
  vector<vi> res=CountTrip(nums);
  for(auto it:res)
  {
    for(auto it1:it)  cout<<it1<<" ";
    cout<<"\n";
  }
	return 0;
}
