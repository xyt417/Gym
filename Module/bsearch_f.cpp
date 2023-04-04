#include<bits/stdc++.h>
using namespace std;
double bsearch_f(int low, int high, double value){
    int l=low, r=high;
    while(r-l>1e-7){
        int mid=l+r>>1;
        if(mid*mid*mid<value) l=mid;
        else r=mid;
    }
    return l;
}
int main(){
    double n;
    cin>>n;
    cout<<fixed<<setprecision(6)<<bsearch_f(-10000, 10000, n);
    return 0;
}