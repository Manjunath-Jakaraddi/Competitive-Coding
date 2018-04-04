#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
#define epsilon 0.0000001
int main()
{
  int n;
  cin>>n;
  if(n<4)
  {
    cout<<"YES";
    return 0;
  }
  int x1,x2,y1,y2;
  cin>>x1>>y1>>x2>>y2;
  float slopes[2];
  int k=1;
  slopes[0]=(1.0*(y2-y1)/(x2-x1));
  vii upr;
  bool ok=true;
  for(int i=2;i<n;i++)
  {
    cin>>x1>>y1;
    float x=(1.0*(y1-y2)/(x1-x2));
    for(int j=0;j<k;j++)
    {
      if(!(abs(slopes[j]-x)<epsilon))
      {
        if(upr.size()==0) upr.push_back({x1,y1});
        else if(k==1)
        {
          k++;
          slopes[1]=(1.0*(y1-upr[0].second)/(x1-upr[0].first));
          break;
        }
        else
          ok=false;
      }
    }
    if(!ok) break;
  }
  for(int j=0;j<k;j++)  cout<<slopes[j]<<" ";
  ok?cout<<"YES":cout<<"NO";
	return 0;
}
