#include<bits/stdc++.h>
using namespace std;
const int N = 100010;

// ############# 邻接表 #############
int h[N], e[N], ne[N], idx;

// 添加一条边 a->b
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

// 初始化
void init(){
    memset(h, -1, sizeof(h));
    // idx = 0;
}
