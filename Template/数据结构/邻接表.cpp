#include<bits/stdc++.h>
using namespace std;
const int N = 100010;

// ############# 邻接表 #############
int h[N], e[N], ne[N], w[N], idx;

// 添加一条边 a->b 边长为c
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

// 初始化
void init(){
    memset(h, -1, sizeof(h));
    // idx = 0;
}
