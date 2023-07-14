#include<iostream>
using namespace std;
bool isPower2(int x);
int main() {
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        int cnt = __builtin_popcount(x);
        if (cnt < 4) {
            cout <<"-1\n";
        } else {
            int cnt2=0;
            for (int i=0; i<32; i++) {
                if (x & ((1 <<i))) {
                    cout << (1<<i) << " ";
                    cnt2++;
                    if (cnt2 > 4) {
                        break;
                    }
                }
            }
            cout<<"\n";
        }

    }
}

bool isPower2(int x) {
    return ((x & (x-1)) == 0);
}