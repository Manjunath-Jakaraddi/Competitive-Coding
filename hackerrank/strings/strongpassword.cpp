#include<bits/stdc++.h>
using namespace std;

int find(char a)
{
    if(a<='9'&&a>='0')   return 3;
    if(a>='a'&&a<='z')   return 2;
    if(a>='A'&&a<='Z')   return 1;
    return 0;
}
int main() {
    int n;
    string s;
    cin>>n>>s;
    map<int,int> mmap;
    for(char a:s)
        mmap[find(a)]=1;
    int n2=mmap.size();
    cout<<max(6-n,4-n2)<<"\n";
    return 0;
}
