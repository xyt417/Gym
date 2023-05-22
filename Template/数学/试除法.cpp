#include<bits/stdc++.h>
using namespace std;

// 试除法判断素数
bool is_prime(int x){
    if(x < 2) return false;
    for(int i = 2; i <= x / i; ++ i)
        if(x % i == 0) return false;
    return true;
}
// 试除法分解质因数[867.分解质因数]
void divide(int x){
    for(int i = 2; i <= x / i; ++ i){
        if(x % i == 0) {
            int s = 0;
            while(x % i == 0) x /= i, s ++; // i: 底数 s: 指数
            cout << i << ' ' << s << '\n';
        }
    }
    if(x > 1) cout << x << ' ' << 1 << '\n';
    cout << '\n';
}