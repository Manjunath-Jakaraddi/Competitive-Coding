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
struct TrieNode
{
  TrieNode *left=NULL,*right=NULL;
  int val;
};
void insert(int n,TrieNode *root)
{
  TrieNode *cur=root;
  for(int i=31;i>=0;i--)
  {
    if((n>>i)&1)
    {
      if(!cur->left)  cur->left=new TrieNode();
      cur=cur->left;
    }
    else
    {
      if(!cur->right) cur->right=new TrieNode();
      cur=cur->right;
    }
  }
  cur->val=n;
}
int querymaxXor(int n,TrieNode *root)
{
  TrieNode *cur=root;
  for(int i=31;i>=0;i--)
  {
    if((n>>i)&1)
    {
      if(cur->right)  cur=cur->right;
      else  cur=cur->left;
    }
    else
    {
      if(cur->left) cur=cur->left;
      else  cur=cur->right;
    }
  }
  return (n^cur->val);
}
int n;
int arr[100];
int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i];
  int mxxor=INT_MIN,pre_xor=0;
  TrieNode *root=new TrieNode();
  insert(0,root);
  for(int i=0;i<n;i++)
  {
    pre_xor^=arr[i];
    insert(pre_xor,root);
    mxxor=max(mxxor,querymaxXor(pre_xor,root));
  }
  cout<<mxxor<<"\n";
  return 0;
}
