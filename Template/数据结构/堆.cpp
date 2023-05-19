#include<bits/stdc++.h>
using namespace std;
const int N = 100010;

// ############# 堆 ###############
int h[N], sz;
// h[N]存储堆中的值，h[1]是堆顶，x的左儿子是 2x，右儿子是 2x + 1
void down(int u){ // 下沉
    int t = u;
    if(u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if(u != t){
        swap(h[u], h[t]);
        down(t);
    }
}

void up(int u){ // 上浮
    while(u / 2 && h[u] < h[u / 2]){
        swap(h[u], h[u / 2]);
        u /= 2;
    }
}

void push(int u){
    h[++ sz] = u;
    up(sz);
}

int pop(){
    int t = h[1];
    swap(h[1], h[sz --]);
    down(1);
    return t;
}

// [838.堆排序]
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; ++ i){
        int x;
        cin >> x;
        push(x);
    }
    while(m --){
        cout << pop() << " \n"[m == 0];
    }
    return 0;
}