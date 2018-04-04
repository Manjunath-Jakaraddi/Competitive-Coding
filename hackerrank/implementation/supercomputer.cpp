#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000007
string s1[20],s2[20];
int m,n;
int main()
{
  cin>>m>>n;
  for(int i=0;i<m;i++)  cin>>s1[i];
  int area=0;
  for(int i=0;i<m;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(s1[i][j]=='B')  continue;
      for(int i=0;i<m;i++)  s2[i]=s1[i];
      int ct=1;
      s2[i][j]='B';
      while(i+ct<m&&i-ct>-1&&s2[i+ct][j]=='G'&&s2[i-ct][j]=='G'&&j-ct>-1&&j+ct<n&&s2[i][j-ct]=='G'&&s2[i][j+ct]=='G')
      {
        s2[i+ct][j]='B';
        s2[i-ct][j]='B';
        s2[i][j-ct]='B';
        s2[i][j+ct]='B';
        ct++;
      }
      ct--;
      int ctt=-1;
      for(int k=0;k<m;k++)
      {
        for(int l=0;l<n;l++)
        {
          if(s2[k][l]=='B') continue;
          int pt=1;
          while(k+pt<m&&k-pt>-1&&l+pt<n&&l-pt>-1&&s2[k+pt][l]=='G'&&s2[k-pt][l]=='G'&&s2[k][l-pt]=='G'&&s2[k][l+pt]=='G')
            pt++;
          pt--;
          ctt=max(ctt,pt);
        }
      }
      area=max(area,((ct*4+1)*(ctt*4+1)));
    }
  }
  cout<<area<<"\n";
  return 0;
}
