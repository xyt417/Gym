#include<bits/stdc++.h>
using namespace std;
#define SIZE 100010

// ##################### Bsearch L&R #########################
int bsearch_L(int q[], int l, int r, int val){
    while(l<r){
        int mid=l+r>>1;
        if(q[mid]>=val) r=mid;
        else l=mid+1;
    }
    return q[l]==val?l:-1;
}
int bsearch_R(int q[], int l, int r, int val){
    while(l<r){
        int mid=l+r+1>>1;
        if(q[mid]<=val) l=mid;
        else r=mid-1;
    }
    return q[l]==val?l:-1;
}
// ############################################################

// #################### Test(789.数的范围) #####################
int q[SIZE];
int main(){
    int n, Q;
    cin>>n>>Q;
    for(int i=0; i<n; ++i)
        cin>>q[i];
    while(Q--){
        int val;
        cin>>val;
        cout<<bsearch_L(q, 0, n-1, val)<<" "<<bsearch_R(q, 0, n-1, val)<<'\n';
    }
    return 0;
}
// ############################################################
