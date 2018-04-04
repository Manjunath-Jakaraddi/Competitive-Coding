#include<bits/stdc++.h>
#define fori(n) for(int i=0;i<n;i++)
#define forj(n) for(int j=0;j<n;j++)
using namespace std;
int main()
{
    int x,y;
    int cnt=0;
    cin>>x>>y;
//    while(x&&y)
//    {
//        if((x-y)<2)
//        {
//            x=min(x+2,100);
//            y=max(y-4,0);
/*	    cnt++;
        }
        else if((y-x)<2)
	{
		x=max(x-4,0);
		y=min(y+2,100);
		cnt++;
	}
	else if(x>y)
        {
            x=max(x-2,0);
            y=min(y++,100);
        }
	else
	{
		x=min(x++,100);
		y=max(y-2,100);
	}
    cnt++;
    }
*/
	while((x>1||y>1)&&(x&&y))
	{
		if(x<y)	x++,y-=2,cnt++;
		else x-=2,y++,cnt++;	
	}
    cout<<cnt;
    return 0;
}
