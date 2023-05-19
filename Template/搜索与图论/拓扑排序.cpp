#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int q[N], d[N]; // d[i]表示i节点的入度
int h[N], e[N], ne[N], idx; 
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
    ++ d[b];
}
bool topsort(){ // 返回是否存在拓扑序列
    int hh = 0, tt = -1;
    for(int i = 1; i <= n; ++ i)
        if(!d[i])
            q[++ tt] = i;
    while(hh <= tt){
        for(int i = h[q[hh ++]]; i != -1; i = ne[i]){
            int j = e[i];
            if(-- d[j] == 0)
                q[++ tt] = j;
        }
    }
    return tt == n - 1;
}

// [有向图的拓扑序列]
int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m --){
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    if(topsort())
        for(int i = 0; i < n; ++ i) cout << q[i] << ' ';
    else
        cout << -1;
}