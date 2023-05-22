/**
    如果 N = p1 ^ c1 * p2 ^ c2 * ... * pk ^ ck
    那么约数个数为 (c1 + 1) * (c2 + 1) * ... * (ck + 1)
    约数之和为 (p1 ^ 0 + p1 ^ 1 + ... + p1 ^ c1) * ... * (pk ^ 0 + pk ^ 1 + ... + pk ^ ck)
**/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL Mod = 1e9 + 7;
int n;
// [870 & 871. 约数个数 & 约数之和]
int main(){
    unordered_map<LL, LL> primes;
    LL a, res = 1;
    cin >> n;
    while(n --){
        cin >> a; 
        for(int i = 2; i <= a / i; ++ i){
            while(a % i == 0){
                primes[i] ++;
                a /= i;
            }
        }
        if(a > 1) primes[a] ++;
    }
    // 约数个数:
    // for(auto &i : primes) res *= i.second + 1, res %= Mod;
    // 约数之和:
    for(auto &i : primes){
        LL q = 0;
        for(int j = 0; j <= i.second; ++ j){
            LL p = 1;
            for(int k = 0; k < j; ++ k) p *= i.first, p %= Mod;
            q += p, q %= Mod;
        }
        res *= q, res %= Mod;
    }
    cout << res;
    return 0;
}