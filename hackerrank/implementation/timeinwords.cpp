#include<bits/stdc++.h>
using namespace std;
string str[30]={
    "one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve",
    "thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
    "twenty one","twenty two","twenty three","twenty four","twenty five","twenty six",
    "twenty seven","twenty eight","twenty nine","thirty"
};
string str2[3]={"quarter past ","half past ","quarter to "};
int main() {
    int h,m;
    cin>>h>>m;
    h--;
    if(m==0)    cout<<str[h]<<" o' clock\n";
    else
    {
        if(m%15==0)
        {
            cout<<str2[(m/15)-1];
            if(m/15==3)     cout<<str[(h+1)%12]<<"\n";
            else            cout<<str[h]<<"\n";
        }
        else
        {
            if(m<30)
            {
                cout<<str[m-1];
                m==1?cout<<" minute past ":cout<<" minutes past ";
                cout<<str[h]<<"\n";
            }
            else
            {
                cout<<str[60-m-1];
                m==1?cout<<" minute past ":cout<<" minutes to ";
                cout<<str[(h+1)%12]<<"\n";
            }
        }
    }
    return 0;
}
