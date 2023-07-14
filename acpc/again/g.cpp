#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

int main() {
    int k;
    cin>>k;
    int cnt = __builtin_popcount(k);
    long long ans = pow(26, cnt);
    cout << ans << "\n";

    // vector<long long> dp(k+1, 0);
    // dp[0] = 1;
    // for (int i=1; i<=k; i++) {
    //     dp[i] = dp[i/2];
    //     if (i&1)    dp[i]= (dp[i] * 26L);
    // }
    // cout << dp[k] << "\n";
}