#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[26];
int main() {
    string s;
    cin>>s;
    long long ans=0;
	for(int i=0;i<s.length();i++)	a[s[i]-'a']++;
    int mini=*upper_bound(a,a+26,0);
    int maxi=*max_element(a,a+26);
    ans=2*(pow(mini,3)+pow(maxi,3));
    cout<<ans<<endl;
    return 0;
}
