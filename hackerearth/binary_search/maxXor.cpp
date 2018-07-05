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
class TrieNode
{
  public:
    TrieNode *left=NULL,*right=NULL;
    int val;
};
void Insert(int n,TrieNode *root)
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
int query(int n,TrieNode *root)
{
  TrieNode *cur=root;
  for(int i=31;i>=0;i--)
  {
    if((n>>i)&1)
    {
      if(cur->right) cur=cur->right;
      else  cur=cur->left;
    }
    else
    {
      if(cur->left)  cur=cur->left;
      else  cur=cur->right;
    }
  }
  return (n^cur->val);
}
int n,q,x;
int main()
{
	prep();
  cin>>n;
  TrieNode *root=new TrieNode();
  loop(i,n)
  {
    cin>>x;
    Insert(x,root);
  }
  cin>>q;
  while(q--)
  {
    cin>>x;
    cout<<query(x,root)<<"\n";
  }
	return 0;
}
