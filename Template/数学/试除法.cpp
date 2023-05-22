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

// 试除法求约数
vector<int> get_divisors(int x){
    vector<int> res;
    for(int i = 1; i <= x / i; ++ i){
        if(x % i == 0){
            res.push_back(i);
            if(i != x / i) res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}