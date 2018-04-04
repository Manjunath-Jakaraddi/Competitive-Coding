#include <bits/stdc++.h>

using namespace std;
int k;
vector <int> circularArrayRotation(vector <int> a, vector <int> m) {
    vector<int> res;
    int n=a.size();
    cout<<k;
    for(int i=0;i<m.size();i++)     res.push_back(a[(m[i]+k+1)%n]);
    return res;
}

int main() {
    int n;
    int q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> a[a_i];
    }
    vector<int> m(q);
    for(int m_i = 0; m_i < q; m_i++){
       cin >> m[m_i];
    }
    vector <int> result = circularArrayRotation(a, m);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? "\n" : "");
    }
    cout << endl;


    return 0;
}
