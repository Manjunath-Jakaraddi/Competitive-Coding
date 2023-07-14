#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int nax = 1e5+5;
void find_ans(int q, vector<bool> dp);
int main()
{
    vector<bool> dp(nax, 0);
    dp[0] = 1;
    for (int i=4; i<=100000; i++) {
        for (int p1=0; p1<13; p1++) {
            int n1 = (1 << p1);
            if ((i-n1) < 0) continue;
            for (int p2=0; p2<13; p2++) {
                int n2 = (1<<p2);
                if ((i-(n1+n2)) < 0) continue;
                for (int p3=0; p3<13; p3++) {
                    int n3 = (1<<p3);
                    if ((i-(n1+n2+n3)) < 0)    continue;
                    int n4 = i - (n1+n2+n3);
                    if (i-(n1+n2+n3+n4) < 0)    continue;
                    if ((n4 & (n4-1))) continue;
                    if (dp[i-(n1+n2+n3+n4)]) {
                        dp[i] = true;
                    }
                }
            }
        }
    }
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        int q;
        cin>>q;
        if (q < 4 || q > 100000) cout<<"-1\n";
        else {
            if ((!dp[q])) {
                cout << "-1\n";
            }
            else find_ans(q, dp);
        }
    }
	return 0;
}


void find_ans(int q, vector<bool> dp) {
    for (int p1=0; p1<13; p1++) {
        int n1 = (1 << p1);
        if ((q-n1) < 0) continue;
        for (int p2=0; p2<13; p2++) {
            int n2 = (1<<p2);
            if ((q-(n1+n2)) < 0) continue;
            for (int p3=0; p3<13; p3++) {
                int n3 = (1<<p3);
                if ((q-(n1+n2+n3)) < 0)    continue;
                int n4 = q - (n1+n2+n3);
                if ((q-(n1+n2+n3+n4)) < 0)    continue;
                if ((n4 & (n4-1))) continue;
                if (dp[q-(n1+n2+n3+n4)] || (dp[q-n1] && dp[q-n2] && dp[q-n3] && dp[q-n4])) {
                    cout << n1 << " " << n2 << " " << n3 << " " << n4 << "\n";
                    return;
                }
            }
        }
    }
}
