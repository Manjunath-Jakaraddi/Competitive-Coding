#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
inline void prep()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
}
int main() {
    prep();
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        int cnt = __builtin_popcount(x);
        if (cnt > 4 || cnt == 0) {
            cout <<"-1\n";
            continue;
        }
        vector<int> ans;
        for (int i=0; i<31; i++) {
            if ((x&(1<<i))) ans.push_back((1<<i));
        }
        reverse(ans.begin(), ans.end());
        int ind = 0;
        while(ans.size()<4 && ind < ans.size() && ans[ind] > 1) {
            int val = ans[ind]/2;
            ans[ind]/=2;
            ans.push_back(val);
            if (ind < ans.size() && ans[ind] == 1) {
                ind++;
            }
        }
        if (ans.size() != 4) {
            cout <<"-1\n";
        } else {
            for (int a : ans) {
                cout << a << " ";
            }
            cout <<"\n";
        }
    }
    return 0;
}