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
// class Node
// {
//   public:
//     Node *left,*right;
//     ll val;
//     Node(ll val)
//     {
//       this->val=val;
//     }
// };
// Node* Insert(Node *root,ll val)
// {
//   Node *curr=root;
//   if(!root) return (Node *)(new Node(val));
//   if(val>root->val)
//     root->right=Insert(root->right,val);
//   else if(val<root->val)
//     root->left=Insert(root->left,val);
//   return root;
// }
// void inorder(Node *root)
// {
//   if(!root) return;
//   inorder(root->left);
//   cout<<root->val<<" ";
//   inorder(root->right);
// }
// ll findMax(Node *root,int key)
// {
//   if(!root) return 0;
//   while(root->right!=NULL)
//   {
//     root=root->right;
//   }
//   return root->val;
// }
// ll getMinGreaterThan(Node *root,ll key)
// {
//   if(!root) return 0;
//   if(key>root->val)  return getMinGreaterThan(root->right,key);
//   else if(key<root->val) return getMinGreaterThan(root->left,key);
//   else  return findMax(root->left,key);
// }
ll t,n,m;
ll arr[100005],sm[100005];
void solve()
{
  cin>>n>>m;
  set<ll> st;
  st.insert(0);
  ll res=0,pref=0,x;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    pref=(pref+x)%m;
    res=max(res,pref);
    auto it=st.lower_bound((pref+1)%m);
    if(it!=st.end())  res=max(res,(pref-(*it)+m)%m);
    st.insert(pref);
  }
  cout<<res<<"\n";
}
int main()
{
	prep();
  cin>>t;
  while(t--)  solve();
	return 0;
}
