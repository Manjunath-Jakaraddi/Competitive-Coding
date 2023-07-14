#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
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
#define oo 987654321
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int main()
{
    prep();
    int arr[2][2];
    cin>> arr[0][0] >> arr[0][1] >> arr[1][0] >> arr[1][1];
    int mx = max({arr[0][0], arr[0][1], arr[1][0], arr[1][1]});
    bool left = false, bottom = false;
    if (arr[0][0] == arr[0][1] && 2 * arr[0][0] > mx) {
        // right or left
        mx = 2 * arr[0][0];
        left = true;
    }
    if (arr[0][0] == arr[1][0] && (2 * arr[0][0] > mx)) {
        mx = (2 * arr[0][0]);
        bottom = true;
    }
    if (arr[0][1] == arr[1][1] && (2*arr[0][1] > mx)) {
        mx = (2 * arr[0][1]);
        bottom = true;
    }
    if (arr[1][0] == arr[1][1] && (2 *arr[1][0] > mx)) {
        mx = (2 * arr[1][0]);
        left = true;
    }
    cout << mx << "\n";
    if (!left && !bottom) {
        cout <<"up";
    } 
    if (left) {
        cout << "left";
    }
    if (bottom) {
        cout << "up";
    }
	return 0;
}