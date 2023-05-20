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
    dist[1] = 0, st[1] = true;
    for(int i = 1; i < n; ++ i){
        int t = -1;
        for(int j = 1; j <= n; ++ j)
            if(!st[j] && (t == -1 || dist[j] < dist[t])){
                t = j;
                cout << t << endl;
            }
        if(dist[t] == INF) return INF;
        for(int j = 1; j <= n; ++j)
            dist[j] = min(dist[j], g[t][j]);
        res += dist[t];
        st[t] = true;
    }
    return res;
}

int main(){
    cin >> n >> m;
    memset(g, 0x3f, sizeof(g));
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        g[x][y] = min(g[x][y], z);
    }
    int res = prim();
    if(res == INF) cout << "impossible";
    else cout << res;
    return 0;
}