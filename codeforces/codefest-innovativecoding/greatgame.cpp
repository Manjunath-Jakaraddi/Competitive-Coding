#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ans;
vector<int> v;
bool comp(int a,int b)
{
    if(a<=b)    ans++;
    cout<<a<<" "<<b<<endl;
    return a<b;
}
template<class Iter>
void merge_sort(Iter first, Iter last){
    if (last - first > 1) {
        Iter middle = first + (last - first) / 2;
        merge_sort(first, middle);
        merge_sort(middle, last);
        inplace_merge(first, middle, last,comp);
    }
}

int main() {
     int n;
    cin>>n;
	int x;
    for(int i=0;i<n;i++){  cin>>x; v.push_back(x);}
    merge_sort(v.begin(), v.end());
    cout<<ans;
    return 0;
}

