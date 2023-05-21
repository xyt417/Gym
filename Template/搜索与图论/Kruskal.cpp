#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
const int INF = 0x3f3f3f3f;

int p[N]; // 存在多个集合用并查集，只有两种集合可用st数组
int n, m;

int find(int x){
    if(x != p[x]) return p[x] = find(p[x]); // 路径压缩
    return x;
}

struct Edge{
    int a, b, w;
    bool operator<(Edge &W){
        return w < W.w;
    }
}edges[N * 2];

int kruskal(){
    sort(edges, edges + m); // 按边权从小到大排序 (边从0开始编号)
    for(int i = 1; i <= n; ++ i) p[i] = i; // 初始化并查集
    int res = 0, cnt = 0;
    for(int i = 0; i < m; ++ i){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if(a != b){
            p[a] = b;
            res += w;
            cnt ++;
        }
    }
    if(cnt < n - 1) return INF;
    return res;
}
// [Kruskal求最小生成树]
int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++ i){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    int ans = kruskal();
    if(ans == INF) cout << "impossible";
    else cout << ans;
    return 0;
}