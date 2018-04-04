#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,c;
        int cur,wrap;
        cin>>n>>m>>c;
        cur=(n/m);
        wrap=(n/m);
        while((wrap/c)>0)
        {
            cur+=(wrap/c);
            wrap=(wrap/c)+(wrap%c);
        }
        cout<<cur<<"\n";
    }
    return 0;
}
