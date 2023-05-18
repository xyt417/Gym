// [830.单调栈]
#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int stk[N];
int tt = -1;
int n;
int main(){
    cin >> n;
    while(n --){
        int x;
        cin >> x;
        while(tt > -1 && stk[tt] >= x) -- tt; // while(tt > -1 && check()) -- tt;
        if(tt == -1) cout << -1 << ' ';
        else cout << stk[tt] << ' ';
        stk[++ tt] = x; // stk[++ tt] = x;
    }
    return 0;
}