#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
typedef pair<int, int> PII;

int h[N], e[N], ne[N], w[N], idx; // 邻接表: 稀疏图、顶点数较多  w[i]表示i节点的权值
int dist[N];
bool st[N];
int n, m;
void add(int x, int y, int z){
    e[idx] = y, w[idx] = z, ne[idx] = h[x], h[x] = idx ++;
}

int dijkstra(){
    // 初始化
    memset(dist, 0x3f, sizeof(dist)); // 0x3f足够大且防溢出
    dist[1] = 0; // 起点距离为0
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 小根堆 {距离, 节点编号}
    heap.push({0, 1});
    while(!heap.empty()){
        // 取出最小距离的点
        PII t = heap.top();
        heap.pop();
        if(st[t.second]) continue; // 跳过已经确定最小距离的点
        st[t.second] = true; // t已经确定最小距离
        // 用t更新其他点
        for(int i = h[t.second]; i != -1; i = ne[i]){
            int j = e[i];
            if(t.first + w[i] < dist[j]){
                dist[j] = t.first + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if(dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

// [Dijkstra求最短路II]
int main(){
    memset(h, -1, sizeof(h));
    cin >> n >> m;
    while(m --){
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    cout << dijkstra();
}