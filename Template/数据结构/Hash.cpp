#include<bits/stdc++.h>
using namespace std;
const int N = 100010;

// ############# Hash #############

// ### 拉链法 ###
int h[N], e[N], ne[N], idx;

// 初始化
void init(){
    memset(h, -1, sizeof(h));
    idx = 0;
}

// 向哈希表中插入一个数
void insert(int x){
    int k = (x % N + N) % N; // 正数
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx ++;
}

// 在哈希表中查询某个数是否存在
bool find(int x){
    int k = (x % N + N) % N;
    for(int i = h[k]; i != -1; i = ne[i]){
        if(e[i] == x) return true;
    }
    return false;
}

// ### 开放寻址法 ###
int h2[N];

// 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
int find2(int x){
    int k = (x % N + N) % N;
    while(h2[k] != 0 && h2[k] != x){
        k ++; // 线性探测
        if(k == N) k = 0;
    }
    return k;
}

// ### 字符串哈希 ###
// 核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
// 取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果
typedef unsigned long long ULL;
const int P = 131;
ULL h3[N], p[N];

// 初始化
void init(string &str){
    p[0] = 1;
    int n = str.size();
    for(int i = 1; i <= n; ++ i){
        h3[i] = h3[i - 1] * P + str[i - 1];
        p[i] = p[i - 1] * P;
    }
}

// 计算子串str[l ~ r]的哈希值
ULL get(int l, int r){
    return h3[r] - h3[l - 1] * p[r - l + 1];
}

// [841.字符串哈希]
int main(){
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    init(str);
    while(m --){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << (get(l1, r1) == get(l2, r2) ? "Yes" : "No") << endl;
    }
    return 0;
}