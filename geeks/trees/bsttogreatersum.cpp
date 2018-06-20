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
struct Node
{
  int data;
  struct Node *left, *right;
};
struct Node *newNode(int item)
{
  struct Node *temp =  new Node;
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}
void inorder(Node *root)
{
  if(!root) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}
int sm=0;
void greaterSum(Node *root)
{
  if(!root) return ;
  greaterSum(root->right);
  sm+=root->data;
  root->data=(sm-root->data);
  greaterSum(root->left);
}
int main()
{
	prep();
  struct Node *root = newNode(11);
  root->left = newNode(2);
  root->right = newNode(29);
  root->left->left = newNode(1);
  root->left->right = newNode(7);
  root->right->left = newNode(15);
  root->right->right = newNode(40);
  root->right->right->left = newNode(35);
  inorder(root);  cout<<"\n";
  greaterSum(root);
  inorder(root);
	return 0;
}
