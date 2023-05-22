const int N = 100010;
int primes[N], cnt;
bool st[N];

// 朴素筛 O(nloglogn)
void get_primes1(int n){
    for(int i = 2; i <= n; ++ i){
        if(st[i]) continue;
        primes[cnt ++] = i;
        for(int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}
// 线性筛 O(n)
void get_primes2(int n){
    for(int i = 2; i <= n; ++ i){
        if(!st[i]) primes[cnt ++] = i;
        for(int j = 0; primes[j] <= n / i; ++ j){
            st[primes[j] * i] = true;     // pj 是小于等于 i 的最小质因子 -> pj 是 pj * i 的最小质因子
            if(i % primes[j] == 0) break; // 保证 pj 是 i 的最小质因子 (pj <= i)
        }                                 // 每个数有且只有一个最小质因子，所以每个数只会被其筛掉一次，故复杂度为线性的
    }
}