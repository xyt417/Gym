// [滑动窗口]
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int q[N];
int x[N];
int hh = 0, tt = -1;
int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++ i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++ i){
        while(tt >= hh && q[hh] < x[i] || tt - hh + 1 == k) ++ hh;
        while(tt >= hh && q[tt] < x[i]) -- tt;
        q[++ tt] = x[i];              
        if(i >= k - 1)                 
            cout << q[hh] << ' ';  
    }                              
    cout << '\n';                  
    // reset                       
    hh = 0, tt = -1;               
    for(int i = 0; i < n; ++ i){   
        while(tt >= hh && q[hh] > x[i] || tt - hh + 1 == k) ++ hh;
        while(tt >= hh && q[tt] > x[i]) -- tt;
        q[++ tt] = x[i];
        if(i >= k - 1)
            cout << q[hh] << ' '; 
    }
    return 0;
}