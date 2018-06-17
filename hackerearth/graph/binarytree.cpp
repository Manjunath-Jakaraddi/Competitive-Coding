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
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* create(int l,int r,vector<int>& nums)
{
    TreeNode *tmp=new TreeNode(nums[(l+r)/2+1]);
    cout<<l<<" "<<r<<"\n";
    if(l<=r)
    {
        tmp->left=create(l,(l+r)/2-1,nums);
        tmp->right=create((l+r)/2+1,r,nums);
    }
    return tmp;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    int n=nums.size();
    TreeNode *root=new TreeNode(nums[(n-1)/2]);
    root->left=create(0,(n-1)/2-1,nums);
    root->right=create((n-1)/2+1,n-1,nums);
    return root;
}
int main()
{
	prep();
  vi nums;
  nums.pb(-10);
  nums.pb(-3);
  nums.pb(0);
  nums.pb(5);
  nums.pb(9);
  sortedArrayToBST(nums);
	return 0;
}
