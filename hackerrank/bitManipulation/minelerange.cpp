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
#define N 100005
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
struct Segnode
{
  int lo,hi,mn,delta,cnt;
} tree[4*N+1];
int left(int p) { return p<<1; }
int right(int p) { return (p<<1)+1; }
// call initialise(1,0,n-1)
void initialise(int i,int L,int R)
{
  tree[i].lo=L;tree[i].hi=R;
  if(L==R)  return;
  initialise(left(i),L,(L+R)/2);
  initialise(right(i),(L+R)/2+1,R);
}
void prop(int i)
{
  tree[left(i)].delta+=tree[i].delta;
  tree[right(i)].delta+=tree[i].delta;
  tree[i].delta=0;
}
void update(int i)
{
  tree[i].mn=min(
    tree[left(i)].mn+tree[left(i)].delta,
    tree[right(i)].mn+tree[right(i)].delta
  );
  if(tree[i].mn==(tree[left(i)].mn+tree[left(i)].delta)&&
    tree[i].mn==(tree[right(i)].mn+tree[right(i)].delta))
      tree[i].cnt=tree[left(i)].cnt+tree[right(i)].cnt;
  else if(tree[i].mn==(tree[left(i)].mn+tree[left(i)].delta))
      tree[i].cnt=tree[left(i)].cnt;
  else if(tree[i].mn==(tree[right(i)].mn+tree[right(i)].delta))
      tree[i].cnt=tree[right(i)].cnt;
}
// Call Update(1,L,R,val) range L to R
void Update(int i,int L,int R,int val)
{
  if(L<tree[i].lo||R>tree[i].hi)  return;
  if(L<=tree[i].lo&&R>=tree[i].hi)
  {
    tree[i].delta+=val;
    if(L==R)  tree[i].cnt=1;
    return ;
  }
  prop(i);
  Update(left(i),L,R,val);
  Update(right(i),L,R,val);
  update(i);
}
// call query(1,L,R)  where L-R range
int query(int i,int L,int R)
{
  if(L>tree[i].hi||R<tree[i].lo)  return 0;
  if(L<=tree[i].lo&&R>=tree[i].hi)
  {
    return tree[i].cnt;
  }
  prop(i);
  int mnleftcnt=query(left(i),L,R);
  int mnrightcnt=query(right(i),L,R);
  update(i);
  if(tree[i].mn==tree[left(i)].mn&&tree[i].mn==tree[right(i)].mn) return mnleftcnt+mnrightcnt;
  else if(tree[i].mn==tree[left(i)].mn) return mnleftcnt;
  else return mnrightcnt;
}
int arr[100];
int n,q,l,r;
int main()
{
	prep();
  cin>>n;
  loop(i,n) cin>>arr[i];
  initialise(1,0,n-1);
  loop(i,n) Update(1,i,i,arr[i]);
  cin>>q;
  while(q--)
  {
    cin>>l>>r;
    cout<<query(1,l-1,r-1)<<"\n";
  }
	return 0;
}
