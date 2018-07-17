#include<bits/stdc++.h>
using namespace std;
int dd1,mm1,yy1,dd2,mm2,yy2;
int main()
{
  cin>>dd1>>mm1>>yy1;
  cin>>dd2>>mm2>>yy2;
  int sm1,sm2;
  if(mm1<3)
  {
    yy1--;
    sm1=(((23*mm1)/9)+dd1+4+(yy1/4)-(yy1/100)+(yy1/400))%7;
  }
  else
  {
    yy1-=2;
    sm1=(((23*mm1)/9)+dd1+4+(yy1/4)-(yy1/100)+(yy1/400))%7;
  }
  cout<<sm1<<" ";
  if(mm2<3)
  {
    yy2--;
    sm2=(((23*mm2)/9)+dd2+4+(yy2/4)-(yy2/100)+(yy2/400))%7;
  }
  else
  {
    yy2-=2;
    sm2=(((23*mm2)/9)+dd2+4+(yy2/4)-(yy2/100)+(yy2/400))%7;
  }
  cout<<sm2<<" ";
  (sm2-(sm1-given day)+7)%7;
  // sturday =0 and so on
	return 0;
}
