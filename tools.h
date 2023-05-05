#ifndef TOOL_H
#define TOOL_H

#include<bits/stdc++.h>

void sort(int q[], int l, int r){
    if(l>=r) return;
    int x=q[l+r>>1], i=l-1, j=r+1;
    while(i<j){
        do ++i; while(q[i]<x);
        do --j; while(q[j]>x);
        if(i<j) std::swap(q[i], q[j]);
    }
    sort(q, l, j), sort(q, j+1, r);
}

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


#endif