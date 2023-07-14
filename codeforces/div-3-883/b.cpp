#include<iostream>
using namespace std;
bool check(string* s, char c) {
    int row[3] = {0, 0, 0}, col[3] = {0, 0, 0}, diag=0, rdiag=0;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if (s[i][j] == c)   {
                row[i]++;
                col[j]++;
                if (i==j)   diag++;
                if (i+j==2) rdiag++;
            }
        }
    }
    for (int i=0; i<3; i++) {
        if (row[i]==3 || col[i] == 3)   return true;
    }
    if (diag == 3 || rdiag == 3)    return true;
    return false;
}
int main() {
    int t;
    cin>>t;
    while(t-->0) {
        string s[3];
        cin>>s[0]>>s[1]>>s[2];
        if (check(s, 'X')) {
            cout<<"X\n";
        } else if (check(s, 'O')) {
            cout<<"O\n";
        } else if (check(s, '+')) {
            cout<<"+\n";
        } else {
            cout<<"DRAW\n";
        }
    }
    return 0;
}