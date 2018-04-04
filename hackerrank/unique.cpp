#include<bits/stdc++.h>
#define N 1000006
#define A 200000009
#define BLOCK 1000
using namespace std;
int cnt[A],a[N],ans[N],answer=0;
struct node
{
    int L,R,i;
}q[N];
bool cmp(node x,node y)
{
    if(x.L/BLOCK!=y.L/BLOCK)
        return x.L/BLOCK < y.L/BLOCK;
    return x.R < y.R;
}
void add(int position)
{
    cnt[a[position]]++;
    if(cnt[a[position]]==1)
    {
        answer++;
    }
    else if(cnt[a[position]]==2)
    {
        answer--;
    }
}
void remove(int position)
{
    cnt[a[position]]--;
    if(cnt[a[position]]==1)
    {
        answer++;
    }
    else if(cnt[a[position]]==0)
    {
        answer--;
    }
}
int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++)    cin>>a[i];
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>q[i].L>>q[i].R;
        q[i].L--;
        q[i].R--;
        q[i].i=i;
    }
    sort(q,q+m,cmp);
    int currentL=0,currentR=0;
    for(int i=0;i<m;i++)
    {
        int L = q[i].L,R = q[i].R;
        while(currentL<L)
        {
            remove(currentL);
            currentL++;
        }
        while(currentL>L)
        {
            add(currentL-1);
            currentL--;
        }
        while(currentR<=R)
        {
            add(currentR);
            currentR++;
        }
        while(currentR>R+1)
        {
            remove(currentR-1);
            currentR--;
        }
        ans[q[i].i]=answer;
    }
    for(int i=0;i<m;i++)   cout<<ans[i]<<endl;
    return 0;
}
