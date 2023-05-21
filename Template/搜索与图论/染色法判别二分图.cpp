#include<bits/stdc++.h>
using namespace std;
const int N = 200010; // 无向图

int h[N], e[N], ne[N], idx;
int color[N];
int n, m;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
bool dfs(int u, int c){ // u:当前节点 c:当前节点颜色
    color[u] = c;
    for(int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if(!color[j]){
            if(!dfs(j, ~ c)) return false;
        }else if(color[j] == c) return false;
    }
    return true;
}
bool check(){ // 非连通图也可以是二分图
    for(int i = 1; i <= n; ++ i)
        if(!color[i])
            if(!dfs(i, 1)) return false;
    return true;
}
// [染色法判定二分图]
int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m --){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a); // 无向图
    }
    if(check()) cout << "Yes";
    else cout << "No";
    return 0;
}