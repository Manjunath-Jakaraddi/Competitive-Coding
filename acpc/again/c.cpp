#include<iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    int n = s.length();
    vector<int> left(n, false), right(n, false);
    for (int i=2; i<n; i++) {
        left[i] = (s.substr(i-2, 3) == "cow");
    }
    for (int i=n-3; i>=0; i--) {
        right[i] = (s.substr(i, 3) == "cow");
    }
    int ans = 0;
    for (int i=1; i<n-3; i++) {
        if (s.substr(i, 3) == "cow" && !left[i-1] && !right[i+3]) {
            ans++;
        }
    }
    cout<<ans<<"\n";
}