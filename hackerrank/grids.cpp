#include<bits/stdc++.h>
using namespace std;

int n,m;
string str[25];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char match[4]={'a','b','c','d'};
bool valid(int i,int j)
{
	    return (i>-1&&i<m&&j>-1&&j<n);
}
bool solve(int x,int y,int k)
{
	    if(k==4)   return true;
	        str[x][y]='z';
		    for(int i=0;i<4;i++)
			        {
					        int nx=x+dir[i][0],ny=y+dir[i][1];
						        if(valid(nx,ny)&&str[nx][ny]==match[k])
								        {
										            if(solve(nx,ny,k+1))  
												                {
															                str[nx][ny]='z';
																	                return true;
																			            }
											            }
							    }
		        return false;
}
int main() {
	    cin>>m>>n;
	        int cnt=0;
		    for(int i=0;i<m;i++)
			            for(int j=0;j<n;j++)
					                cin>>str[i][j];
		        for(int i=0;i<m;i++)
				    {
					            for(int j=0;j<n;j++)
							            {
									                if(str[i][j]=='a'&&solve(i,j,1))
												                cnt++;
											        }
						        }
			    cout<<cnt<<"\n";
			        return 0;
}

