#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
#define loop(i, n) for(int i=0; i<n; i++)
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
string holes_to_logos[3]={"F","O","P"};
int n,m,holes;
string s[55];
void fillgrid(int x,int y,char s1,char s2)
{
  if(x<0||x>=n||y<0||y>=m)  return;
  if(s[x][y]!=s1)  return;
  s[x][y]=s2;
  loop(k,8) fillgrid(x+dx[k],y+dy[k],s1,s2);
}
void dfs(int x,int y)
{
  if(x<0||x>=n||y<0||y>=m)  return;
  if(s[x][y]=='1')
  {
    s[x][y]='W';
    loop(k,8) dfs(x+dx[k],y+dy[k]);
  }
  else if(s[x][y]=='.')
  {
    holes++;
    fillgrid(x,y,'.','B');
  }
}
int main()
{
  string res="";
  cin>>n>>m;
  loop(i,n) cin>>s[i];
  fillgrid(0,0,'.','W');
  loop(i,n)
    loop(j,n)
      if(s[i][j]=='1')
      {
        holes=0;
        dfs(i,j);
        res+=holes_to_logos[holes];
      }
  sort(all(res));
  if(res.length()==0) cout<<"N\n";
  else  cout<<res<<"\n";
	return 0;
}
