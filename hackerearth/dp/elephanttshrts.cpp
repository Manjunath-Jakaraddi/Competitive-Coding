#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define MOD 1000000007
#define pb push_back
#define pf printf
#define sf scanf
#define all(v) v.begin(), v.end()
#define rep(i, s, e) for(auto i=s; i<=e; i++)
#define loop(i, n) for(int i=0; i<n; i++)
#define mp make_pair
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int maximalSquare(vector<vector<char>>& matrix) {
        int mx=0,n=matrix.size();
        vector<vector<int> > mat;
        mat.assign(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            mat[i][0]=matrix[i][0];
            mat[0][i]=matrix[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j])    mat[i][j]=min(mat[i-1][j],min(mat[i-1][j-1],mat[i][j-1]));
                 else mat[i][j]=0;
                mx=max(mx,mat[i][j]);
            }
        }
        return (mx*mx);
    }
int main()
{
	prep();
  int t;
  cin>>t;
  while(t--)
    solve();
  return 0;
}
