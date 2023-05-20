#include<bits/stdc++.h>
using namespace std;
const int N = 1010;

int d[N][N];
int n, m;
void init(){
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= n; ++ j)
            if(i == j) d[i][j] = 0;
            else d[i][j] = 0x3f3f3f3f;
}
void floyd(){
    // 原理: 动态规划 d(k, i, j) = min(d(k - 1, i, j), d(k - 1, i, k) + d(k - 1, k, j))
    // d(k, i, j): 经过前k个点，从i到j的最短距离
    for(int k = 1; k <= n; ++ k)
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= n; ++ j)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
// [Floyd求最短路]
int main(){
    int k;
    cin >> n >> m >> k;
    init();
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        d[x][y] = min(d[x][y], z);
    }
    floyd();
    while(k --){
        int x, y;
        cin >> x >> y;
        if(d[x][y] > 0x3f3f3f3f / 2) cout << "impossible" << endl; // 防止有负权边松弛无穷大
        else cout << d[x][y] << endl;
    }
    return 0;
}