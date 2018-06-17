#include<bits/stdc++.h>
using namespace std;
int main()
{
  int c,s;
  int setno=1;
  while((cin>>c>>s))
  {
    vector<int> val(2*c);
    val.assign(2*c,0);
    for(int i=0;i<s;i++)  cin>>val[i];
    sort(val.begin(),val.end());
    float avg=accumulate(val.begin(),val.end(),0)/(1.0*c),imbal=0;
    cout<<"Set #"<<setno<<"\n";
    for(int i=0;i<val.size()/2;i++)
    {
      cout<<" "<<i<<": ";
      if(val[i])  cout<<val[i]<<" ";
      if(val[2*c-i-1])  cout<<val[2*c-1-i]<<" ";
      imbal+=1.0*abs(val[2*c-i-1]+val[i]-avg);
      cout<<"\n";
    }
    cout<<"IMBALANCE = "<<fixed<<setprecision(6)<<imbal<<"\n\n";
    setno++;
  }
  return 0;
}
