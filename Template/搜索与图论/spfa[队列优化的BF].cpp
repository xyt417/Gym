#include<bits/stdc++.h>
using namespace std;
const int N = 100010;

int h[N], e[N], ne[N], w[N], idx;
int dist[N];
bool st[N];
int n, m;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
// 不能有负环
int spfa(){
    // 初始化dist
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;
    // 初始状态
    queue<int> q;
    q.push(1);
    st[1] = true;
    // 每个被更新过的点都会去尝试更新相邻的点，每个点被更新前都会被当前所有可能更新它的点尝试更新
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false; // 被更新过的点可能还会被更新
        for(int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(dist[j] > dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                if(!st[j]){ // 已经放入队列的点不需要重复放入
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return 2e9;
    return dist[n];
}
// [SPFA求最短路]
int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    int ans = spfa();
    if(ans == 2e9) cout << "impossible";
    else cout << ans;
    return 0;
}