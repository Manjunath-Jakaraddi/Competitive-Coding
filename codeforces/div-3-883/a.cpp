#include<iostream>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t-->0) {
        int n;
        cin>>n;
        int u, l, ans=0;
        for (int i=0; i<n; i++) {
            cin>>u>>l;
            ans += ((u-l)>0);
        }
        cout<<ans<<"\n";
    }
    return 0;
}