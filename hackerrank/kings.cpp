#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define mp make_pair
using namespace std;
const int N=1000002;
int n,m;
int x[N],y[N];
long long sumx[N],sumy[N];

int input(){
    scanf("%d%d",&n,&m);
    for (int i=1,xn,yn;i<=n;i++) {
        scanf("%d%d",&x[i],&y[i]);
        xn=x[i]+y[i];
        yn=x[i]-y[i];
        x[i]=xn;
        y[i]=yn;
    }
    // for(int i=1;i<=n;i++)
    // {
    //   cout<<x[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i=1;i<=n;i++)
    // {
    //   cout<<y[i]<<" ";
    // }
    return 0;
}

int sol(){
    sort(x+1,x+n+1);
    sort(y+1,y+n+1);
    for (int i=1;i<=n;i++){
        sumx[i]=sumx[i-1]+x[i];
        sumy[i]=sumy[i-1]+y[i];
    }
    for(int i=1;i<=n;i++) cout<<sumx[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=n;i++) cout<<sumy[i]<<" ";  
    int xx,yy,xn,yn;
    while (m--){
        scanf("%d%d",&xx,&yy);
        xn=xx+yy;
        yn=xx-yy;
        xx=xn;
        yy=yn;

        xn=lower_bound(x+1,x+n+1,xx)-x;
        yn=lower_bound(y+1,y+n+1,yy)-y;
        printf("%lld\n",
           (1ll*xx*(xn-1)-sumx[xn-1]+
            1ll*yy*(yn-1)-sumy[yn-1]+
            sumx[n]-sumx[xn-1]-1ll*xx*(n-xn+1)+
            sumy[n]-sumy[yn-1]-1ll*yy*(n-yn+1) )/2ll );
    }

    return 0;
}

int main() {
    input();
    sol();
    return 0;
}
