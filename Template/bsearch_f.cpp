#include<bits/stdc++.h>
using namespace std;
// ##################### Bsearch F ########################
double bsearch_f(double low, double high, double value){
    double l=low, r=high;
    while(r-l>1e-7){
        double mid=(l+r)/2;
        if(mid*mid*mid<value) l=mid;
        else r=mid;
        cout << mid << '\n';
    }
    return l;
}
// #########################################################

// #########################  Test  ########################
int main(){
    double n;
    cin>>n;
    cout<<fixed<<setprecision(6)<<bsearch_f(-10000, 10000, n);
    return 0;
}
// ##########################################################