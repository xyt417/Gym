#include<bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];
int prim(){
    memset(dist, 0x3f, sizeof(dist));
    int res = 0;
    dist[1] = 0;
    for(int i = 1; i <= n; ++ i){
        int t = -1;
        for(int j = 1; j <= n; ++ j)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        if(dist[t] == INF) return INF;
        res += dist[t]; // 将t加入最小生成树
        // 先加结果后更新 自环可能更新自己
        for(int j = 1; j <= n; ++j) // 使用t更新其他点到最小生成树的距离
            dist[j] = min(dist[j], g[t][j]);
        st[t] = true;
    }
    return res;
}
// [Prim求最小生成树]
int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = g[y][x] = min(g[x][y], z);
    }
    int res = prim();
    if(res == INF) cout << "impossible";
    else cout << res;
    return 0;
}