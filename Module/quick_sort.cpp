#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
#define SIZE 100010
// ############ My Version ###############
// void quick_sort(int q[], int l, int r){
//     if (l >= r) return;
//     swap(q[l+r>>1], q[l]);
//     int i = l, j = r, x = q[l];
//     while (i < j)
//     {
//         while(j>i && q[j]>x) --j;
//         while(i<j && q[i]<=x) ++i;
//         if (i < j) swap(q[i], q[j]);
//     }
//     swap(q[l], q[j]);
//     quick_sort(q, l, j - 1); quick_sort(q, j + 1, r);
// }
// ! issue: TLE when every element is equal
// ########################################

// ########### Strong Version ##############
void quick_sort(int q[], int l, int r){
    if(l>=r) return;
    int x=q[l+r>>1], i=l-1, j=r+1;
    while(i<j){
        do ++i; while(q[i]<x);
        do --j; while(q[j]>x);
        if(i<j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j+1, r);
}
// ##########################################

// ################ Test ####################
int q[SIZE];
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; ++i)
        cin>>q[i];
    quick_sort(q, 0, n-1);
    for(int i=0; i<n; ++i)
        cout<<q[i]<<' ';
    return 0;
}
// ###########################################