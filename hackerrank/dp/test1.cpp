#include<bits/stdc++.h>
using namespace std;
int func(int x, int y, int z){
int A=0,B=0,C=0;
if(x==0||y==0||z==0)
{
  int res=1;
  if(x) res*=(4*x);
  if(y) res*=(5*y);
  if(z) res*=(6*z);
  return res;
}
A=10*func(x-1,y,z)+4*func(x-1,y,z);
B=10*func(x,y-1,z)+5*func(x,y-1,z);
C=10*func(x,y,z-1)+6*func(x,y,z-1);
cout<<A+B+C<<"\n";
return A+B+C;
}
int main() {
//code
int t, x,y,z;
int i,j,k;
int ans=0;
scanf("%d", &t);
while(t--){
scanf("%d %d %d", &x,&y,&z) ;
for(i=0; i<=x;++i)
for(j=0; j<=y;++j)
for(k=0; k<=z;++k)
ans+=func(i,j,k);
printf("%d",ans);
}
return 0;
}
