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
struct TreeNode
{
  TreeNode *left=NULL,*right=NULL;
  int val;
};
int n;
int arr[100];
TreeNode* ArrtoBST(int start,int end)
{
  if(start>end) return NULL;
  int mid=(start+end)/2;
  TreeNode *root=new TreeNode();
  root->val=arr[mid];
  root->left=ArrtoBST(start,mid-1);
  root->right=ArrtoBST(mid+1,end);
  return root;
}
void inorder(TreeNode *root)
{
  if(!root) return;
  inorder(root->left);
  cout<<root->val<<" ";
  inorder(root->right);
}
int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i];
  TreeNode *root=ArrtoBST(0,n-1);
  inorder(root);
	return 0;
}
