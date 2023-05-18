// [滑动窗口]
// 单调队列 <-> 栈底变化的单调栈
#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
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
        while(tt >= hh && i - q[hh] + 1 > k) ++ hh; // while(tt >= hh && check()) ++ hh;
        while(tt >= hh && x[q[tt]] > x[i]) -- tt; // while(tt >= hh && check()) --tt;
        q[++ tt] = i; // q[++ tt] = i;
        if(i >= k - 1)
            cout << x[q[hh]] << " ";
    }
    cout << '\n';                  
    hh = 0, tt = -1; //reset         
    for(int i = 0; i < n; ++ i){
        while(tt >= hh && i - q[hh] + 1 > k) ++ hh; // while(tt >= hh && check()) ++ hh;
        while(tt >= hh && x[q[tt]] < x[i]) -- tt; // while(tt >= hh && check()) --tt;
        q[++ tt] = i; // q[++ tt] = i;
        if(i >= k - 1)                 
            cout << x[q[hh]] << ' ';  
    }
    return 0;
}