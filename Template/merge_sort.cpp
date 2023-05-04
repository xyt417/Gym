#include<bits/stdc++.h>
using namespace std;
#define SIZE 100010

// ################## Merge Sort #####################
void merge_sort(int q[], int l, int r){
    if(l>=r) return;
    int mid=l+r>>1;
    merge_sort(q, l, mid), merge_sort(q, mid+1, r);
    int i=l, j=mid+1, k=0;
    int temp[SIZE];
    while(i<=mid && j<=r){
        if(q[i]<q[j]) temp[k++]=q[i++];
        else temp[k++]=q[j++];
    }
    while(i<=mid) temp[k++]=q[i++];
    while(j<=r) temp[k++]=q[j++];
    for(int i=l, j=0; i<=r; ++i, ++j) q[i]=temp[j];
}
// ####################################################

// ###################### Test ########################
int q[SIZE];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>q[i];
    merge_sort(q, 0, n-1);
    for(int i=0; i<n; ++i)
        cout<<q[i]<<' ';
    return 0;
}
// #####################################################