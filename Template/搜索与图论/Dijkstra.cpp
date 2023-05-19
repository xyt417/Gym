#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int g[N][N], dist[N]; // 邻接矩阵: 稠密图、顶点数较少
bool st[N];
int n, m;

int dijkstra(){
    // 初始化
    memset(dist, 0x3f, sizeof(dist)); // 0x3f足够大且防溢出
    dist[1] = 0; // 起点距离为0
    for(int i = 0; i < n; ++ i){
        int t = -1;
        // 距离最小未被使用点t
        for(int j = 1; j <= n; ++ j)
            if(!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        // 用t更新其他点
        for(int j = 1; j <= n; ++ j)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

// [Dijkstra求最短路I]
int main(){
    memset(g, 0x3f, sizeof(g));
    cin >> n >> m;
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    cout << dijkstra();
    return 0;
}